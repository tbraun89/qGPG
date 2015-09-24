#include "encryptwidget.h"
#include "ui_encryptwidget.h"

#include "crypto/keys.h"
#include "crypto/plainmessage.h"

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

void EncryptWidget::loadKeys()
{
    for (auto key : Keys::getPublicKeys())
    {
        ui->publicKey->addItem(QString(key.second.c_str()), QString(key.first.c_str()));
    }

    ui->signingKey->addItem(tr("-"), QString());

    for (auto key : Keys::getSecretKeys())
    {
        ui->signingKey->addItem(QString(key.second.c_str()), QString(key.first.c_str()));
    }
}

void EncryptWidget::on_encryptButton_clicked()
{
    std::string  encryptedText;
    PlainMessage plainMessage(ui->textToEncrypt->toPlainText().toStdString());
    QString      publicKey  = ui->publicKey->itemData(ui->publicKey->currentIndex()).toString();
    QString      signingKey = ui->signingKey->itemData(ui->signingKey->currentIndex()).toString();

    if (signingKey.isEmpty())
    {
        encryptedText = plainMessage.encrypt(publicKey.toStdString());
    }
    else
    {
        encryptedText = plainMessage.encrypt(publicKey.toStdString(), signingKey.toStdString());
    }

    ui->textToEncrypt->setPlainText(QString(encryptedText.c_str()));
}

void EncryptWidget::on_signButton_clicked()
{
    std::string  signedText;
    PlainMessage plainMessage(ui->textToEncrypt->toPlainText().toStdString());
    QString      signingKey = ui->signingKey->itemData(ui->signingKey->currentIndex()).toString();

    if (!signingKey.isEmpty())
    {
        signedText = plainMessage.sign(signingKey.toStdString());
        ui->textToEncrypt->setPlainText(QString(signedText.c_str()));
    }
}
