#ifndef DECRYPTWIDGET_H
#define DECRYPTWIDGET_H

#include <QWidget>

namespace Ui {
class DecryptWidget;
}

class DecryptWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DecryptWidget(QWidget *parent = 0);
    ~DecryptWidget();

private:
    Ui::DecryptWidget *ui;
};

#endif // DECRYPTWIDGET_H
