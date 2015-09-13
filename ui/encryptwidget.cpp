#include "encryptwidget.h"
#include "ui_encryptwidget.h"

#include "crypto/keys.h"

EncryptWidget::EncryptWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EncryptWidget)
{
    ui->setupUi(this);
    loadKeys();
}

EncryptWidget::~EncryptWidget()
{
    delete ui;
}

void EncryptWidget::loadKeys() {
    for (auto key : Keys::getPublicKeys())
        ui->publicKey->addItem(QString(key.second.c_str()), QString(key.first.c_str()));

    ui->signingKey->addItem(tr("-"), false);

    for (auto key : Keys::getSecretKeys()) {
        ui->signingKey->addItem(QString(key.second.c_str()), QString(key.first.c_str()));
    }
}
