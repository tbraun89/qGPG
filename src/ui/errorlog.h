#ifndef ERRORLOG_H
#define ERRORLOG_H

#include <QWidget>

namespace Ui {
class ErrorLog;
}

class ErrorLog : public QWidget
{
    Q_OBJECT

public:
    explicit ErrorLog(QWidget *parent = 0);
    ~ErrorLog();

private:
    Ui::ErrorLog *ui;
};

#endif // ERRORLOG_H
