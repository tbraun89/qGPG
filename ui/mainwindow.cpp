#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "encryptwidget.h"

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
    QWidget *encryptWidget = new EncryptWidget;
    ui->tabWidget->addTab(encryptWidget, encryptWidget->windowTitle());
}
