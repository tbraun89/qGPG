#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include "plugin/toolbarinterface.h"

#include <QVector>
#include <QString>
#include <QMessageLogger>

class PluginLoader
{
public:
    struct PluginDefinition {
        QString name;
        QString author;
        QString version;
        QString decription;
    };

    PluginLoader();
    PluginLoader(QString pluginDirectory);

    void loadPlugins();

    void addToolbarActions();

private:
    QMessageLogger              logger;
    QString                     pluginDirectory;
    QVector<ToolbarInterface *> toolbarInterfaces;
};

#endif // PLUGINLOADER_H
