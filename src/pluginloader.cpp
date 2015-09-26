#include "pluginloader.h"

#include <QCoreApplication>
#include <QPluginLoader>
#include <QDir>

PluginLoader::PluginLoader()
{
#if defined(QT_DEBUG)
    pluginDirectory = QString("%1/plugins").arg(QCoreApplication::applicationDirPath());
#elif defined(Q_OS_WIN)
    pluginDirectory = QString("%1/plugins").arg(QCoreApplication::applicationDirPath());
#elif defined(Q_OS_MAC)
    pluginDirectory = "";
#elif defined(Q_OS_LINUX)
    pluginDirectory = "/usr/lib/qGPG/plugins";
#endif
}

void PluginLoader::setPluginDirectory(QString pluginDirectory)
{
    this->pluginDirectory = pluginDirectory;
}

void PluginLoader::loadPlugins()
{
    QDir pluginsDir(pluginDirectory);

    foreach(auto filename, pluginsDir.entryList(QDir::Files))
    {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(filename));
        QObject       *plugin = pluginLoader.instance();

        if (!pluginLoader.isLoaded())
            logger.warning(pluginLoader.errorString().toStdString().c_str());

        if (plugin)
        {
            QJsonObject metaData = pluginLoader.metaData()["MetaData"].toObject();
            logger.debug(QString("Loaded \"%1\" from %2").arg(metaData["name"].toString(), metaData["author"].toString()).toStdString().c_str());

            ToolbarInterface *toolbarInterface = qobject_cast<ToolbarInterface *>(plugin);

            if (toolbarInterface)
                toolbarInterfaces.append(toolbarInterface);
        }
    }
}
