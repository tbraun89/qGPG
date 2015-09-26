#include "pluginloader.h"

#include "plugin/initializeinterface.h"

#include <QCoreApplication>
#include <QPluginLoader>
#include <QDir>

// TODO make this class a singelton to load each plugin only once
// TODO load all available interfaces if a Plugin is loaded
// TODO provide a functions to access the interfaces

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

PluginLoader::PluginLoader(QString pluginDirectory) :
    pluginDirectory(pluginDirectory)
{
}

void PluginLoader::loadPlugins()
{
    QDir pluginsDir(pluginDirectory);

    foreach(auto filename, pluginsDir.entryList(QDir::Files))
    {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(filename));
        QObject       *plugin = pluginLoader.instance();

        if (!pluginLoader.errorString().isEmpty())
            logger.warning(pluginLoader.errorString().toStdString().c_str());

        if (plugin)
        {
            // TODO identify implemented interfaces
        }
    }
}

QVector<PluginLoader::PluginDefinition> PluginLoader::availablePlugins()
{
    return pluginList;
}
