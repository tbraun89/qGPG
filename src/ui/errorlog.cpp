#include "errorlog.h"
#include "ui_errorlog.h"

ErrorLog::ErrorLog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ErrorLog)
{
    ui->setupUi(this);
}

ErrorLog::~ErrorLog()
{
    delete ui;
}

void ErrorLog::addError(QtMsgType type, QString msg)
{
    QListWidgetItem *errorMessage = new QListWidgetItem(msg);

    switch (type) {
    case QtDebugMsg:
        errorMessage->setBackgroundColor(Qt::white);
        break;
    case QtWarningMsg:
        errorMessage->setBackgroundColor(Qt::gray);
        break;
    case QtCriticalMsg:
        errorMessage->setBackgroundColor(Qt::red);
        break;
    case QtFatalMsg:
        errorMessage->setBackgroundColor(Qt::darkRed);
        break;
    }

    ui->errorList->addItem(errorMessage);
}

void ErrorLog::on_clodeButton_clicked()
{
    hide();
}
