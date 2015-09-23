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
