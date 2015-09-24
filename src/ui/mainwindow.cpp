#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "encryptwidget.h"
#include "decryptwidget.h"
#include "errorlog.h"

#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
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
        decryptWidget = new DecryptWidget;
        decryptWidget->setProperty("tabID", "decryptWidgetSingle");
        ui->tabWidget->addTab(decryptWidget, QIcon(":/icons/decrypt") ,decryptWidget->windowTitle());
    }
}

void MainWindow::on_actionEncryptTab_triggered()
{
    if (tabWidgetAddable("encryptWidgetSingle"))
    {
        encryptWidget = new EncryptWidget;
        encryptWidget->setProperty("tabID", "encryptWidgetSingle");
        ui->tabWidget->addTab(encryptWidget, QIcon(":/icons/encrypt"), encryptWidget->windowTitle());
    }
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
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
