#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "encryptwidget.h"
#include "decryptwidget.h"

#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);
    addTabWidgets();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::addTabWidgets() {
    encryptWidget = new EncryptWidget;
    ui->tabWidget->addTab(encryptWidget, encryptWidget->windowTitle());

    decryptWidget = new DecryptWidget;
    ui->tabWidget->addTab(decryptWidget, decryptWidget->windowTitle());
}

void MainWindow::on_actionBugReport_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/tbraun89/qGPG/issues"));
}
