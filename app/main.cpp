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

    PluginLoader::instance().loadPlugins();

    return app.exec();
}
