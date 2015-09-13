#include "encryptwidget.h"
#include "ui_encryptwidget.h"

#include "crypto/keys.h"

EncryptWidget::EncryptWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EncryptWidget)
{
    ui->setupUi(this);
    ui->signWidget->hide();

    loadKeys();
}

EncryptWidget::~EncryptWidget()
{
    delete ui;
}

void EncryptWidget::loadKeys() {
    for (auto key : Keys::getPublicKeys())
        ui->publicKey->addItem(QString(key.second.c_str()), QString(key.first.c_str()));

    ui->signingKey->addItem(tr("Nachricht mit Sender signieren"), false);

    for (auto key : Keys::getSecretKeys()) {
        ui->secretKey->addItem(QString(key.second.c_str()), QString(key.first.c_str()));
        ui->signingKey->addItem(QString(key.second.c_str()), QString(key.first.c_str()));
    }
}

void EncryptWidget::on_signingCheckBox_toggled(bool checked)
{
    if (checked)
        ui->signWidget->show();
    else
        ui->signWidget->hide();
}
