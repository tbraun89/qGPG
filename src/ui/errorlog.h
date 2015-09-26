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
    static ErrorLog& instance() {
        static ErrorLog myInstance;
        return myInstance;
    }
    ~ErrorLog();

    void addError(QtMsgType type, QString msg);

    void hideEvent(QHideEvent *event);

private slots:
    void on_clodeButton_clicked();

private:
    explicit ErrorLog(QWidget *parent = 0);
    ErrorLog(const ErrorLog&);
    ErrorLog& operator = (const ErrorLog&);

    Ui::ErrorLog *ui;

    void saveSettings();

    void loadSettings();
};

#endif // ERRORLOG_H
