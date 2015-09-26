#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

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
        QString path;
    };

    PluginLoader();
    PluginLoader(QString pluginDirectory);

    QVector<PluginDefinition> availablePlugins();

    void loadPlugins();

private:
    QMessageLogger            logger;
    QString                   pluginDirectory;
    QVector<PluginDefinition> pluginList;
};

#endif // PLUGINLOADER_H
