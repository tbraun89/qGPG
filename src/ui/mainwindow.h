#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void addTabWidgets();

private slots:
    void on_actionBugReport_triggered();

private:
    Ui::MainWindow *ui;
    QWidget        *encryptWidget;
    QWidget        *decryptWidget;
};

#endif // MAINWINDOW_H
