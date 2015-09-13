#ifndef ENCRYPTWIDGET_H
#define ENCRYPTWIDGET_H

#include <QWidget>

namespace Ui {
class EncryptWidget;
}

class EncryptWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EncryptWidget(QWidget *parent = 0);
    ~EncryptWidget();

protected:
    void loadKeys();

private slots:
    void on_signingCheckBox_toggled(bool checked);

private:
    Ui::EncryptWidget *ui;
};

#endif // ENCRYPTWIDGET_H
