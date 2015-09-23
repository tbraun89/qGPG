#include "ui/mainwindow.h"
#include "logging.h"

#include <QApplication>
#include <QMessageLogger>

QMessageLogger logger;

int main(int argc, char *argv[]) {
#ifdef QT_DEBUG
    qInstallMessageHandler(consoleHandler);
#endif
    qInstallMessageHandler(fileHandler);
    qInstallMessageHandler(guiHandler);

    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
