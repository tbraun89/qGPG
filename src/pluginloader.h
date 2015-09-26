#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include "plugin/toolbarinterface.h"

#include <QVector>
#include <QString>
#include <QMessageLogger>
#include <QToolBar>

class PluginLoader
{
public:
    static PluginLoader& instance()
    {
        static PluginLoader myInstance;
        return myInstance;
    }
    ~PluginLoader() {}

    // must be called before loadPlugins()
    void setPluginDirectory(QString pluginDirectory);

    // must be called before accessing Plugins
    void loadPlugins();

    void addToolbarActions(QToolBar *toolBar);

private:
    PluginLoader();
    PluginLoader(const PluginLoader&);
    PluginLoader& operator = (const PluginLoader&);

    QMessageLogger              logger;
    QString                     pluginDirectory;
    QVector<ToolbarInterface *> toolbarInterfaces;
};

#endif // PLUGINLOADER_H
