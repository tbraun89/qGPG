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

private slots:
    void on_actionBugReport_triggered();

    void on_actionLog_triggered();

    void on_actionDecryptTab_triggered();

    void on_actionEncryptTab_triggered();

    void on_tabWidget_tabCloseRequested(int index);

private:
    Ui::MainWindow *ui;
    QWidget        *encryptWidget;
    QWidget        *decryptWidget;

    bool tabWidgetAddable(QString name);
};

#endif // MAINWINDOW_H
