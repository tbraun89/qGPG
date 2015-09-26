#include "ui/mainwindow.h"
#include "settings.h"
#include "logging.h"

#include <QApplication>
#include <QMessageLogger>

QMessageLogger logger;

int main(int argc, char *argv[])
{
    qInstallMessageHandler(loggingHandler);

    QCoreApplication::setApplicationName(Settings::APPLICATION_NAME);
    QCoreApplication::setOrganizationDomain(Settings::ORGANIZATION_DOMAIN);
    QCoreApplication::setOrganizationName(Settings::ORGANIZATION_NAME);

    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
