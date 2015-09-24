#include "decryptwidget.h"
#include "ui_decryptwidget.h"

DecryptWidget::DecryptWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DecryptWidget)
{

    ui->setupUi(this);
    ui->consoleList->hide();
}

DecryptWidget::~DecryptWidget()
{
    delete ui;
}
