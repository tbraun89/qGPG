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

PluginLoader::PluginLoader(QString pluginDirectory) :
    pluginDirectory(pluginDirectory)
{
}

void PluginLoader::loadPlugins()
{
    QDir pluginsDir;

    foreach(auto filename, pluginsDir.entryList(QDir::Files))
    {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(filename));
        QObject       *plugin = pluginLoader.instance();

        if (plugin)
        {
            // TODO implement the plugin loading
        }
    }
}

QVector<PluginLoader::PluginDefinition> PluginLoader::availablePlugins()
{
    return pluginList;
}
