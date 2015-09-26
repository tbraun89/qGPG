#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "encryptwidget.h"
#include "decryptwidget.h"
#include "errorlog.h"

#include "settings/settings.h"

#include <QDesktopServices>
#include <QUrl>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadSettings();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionBugReport_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/tbraun89/qGPG/issues"));
}

void MainWindow::on_actionLog_triggered()
{
    ErrorLog::instance().show();
}

void MainWindow::on_actionDecryptTab_triggered()
{
    if (tabWidgetAddable("decryptWidgetSingle"))
    {
        QWidget *decryptWidget = new DecryptWidget;
        decryptWidget->setProperty("tabID", "decryptWidgetSingle");
        ui->tabWidget->addTab(decryptWidget, QIcon(":/icons/decrypt") ,decryptWidget->windowTitle());
    }
}

void MainWindow::on_actionEncryptTab_triggered()
{
    if (tabWidgetAddable("encryptWidgetSingle"))
    {
        QWidget *encryptWidget = new EncryptWidget;
        encryptWidget->setProperty("tabID", "encryptWidgetSingle");
        ui->tabWidget->addTab(encryptWidget, QIcon(":/icons/encrypt"), encryptWidget->windowTitle());
    }
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    QWidget *currentTab = ui->tabWidget->widget(index);
    ui->tabWidget->removeTab(index);
    delete currentTab;
}

bool MainWindow::tabWidgetAddable(QString name)
{
    for (int i = 0; i < ui->tabWidget->count(); ++i)
    {
        if (ui->tabWidget->widget(i)->property("tabID").toString() == name)
        {
            return false;
        }
    }

    return true;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    saveSettings();
    event->accept();
}

void MainWindow::saveSettings()
{
    Settings& settings = Settings::instance();

    settings.saveWidgetProperty(this, "x");
    settings.saveWidgetProperty(this, "y");
    settings.saveWidgetProperty(this, "width");
    settings.saveWidgetProperty(this, "height");
}

void MainWindow::loadSettings()
{
    Settings& settings = Settings::instance();
    int x              = settings.loadWidgetProperty(this, "x").toInt();
    int y              = settings.loadWidgetProperty(this, "y").toInt();
    int width          = settings.loadWidgetProperty(this, "width").toInt();
    int height         = settings.loadWidgetProperty(this, "height").toInt();

    if (x && y)
        move(x, y);

    if (width && height)
        resize(width, height);
}
