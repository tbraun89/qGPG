#include "ui/mainwindow.h"

#include "logging.h"
#include "pluginloader.h"

#include <QApplication>
#include <QMessageLogger>

QMessageLogger logger;

int main(int argc, char *argv[])
{
    qInstallMessageHandler(loggingHandler);

    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();

    PluginLoader pluginLoader;
    pluginLoader.loadPlugins();

    return app.exec();
}
