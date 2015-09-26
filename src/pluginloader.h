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
    };

    PluginLoader();
    PluginLoader(QString pluginDirectory);

    void loadPlugins();

private:
    QMessageLogger            logger;
    QString                   pluginDirectory;
};

#endif // PLUGINLOADER_H
