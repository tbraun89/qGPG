#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "encryptwidget.h"
#include "decryptwidget.h"

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
