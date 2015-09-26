#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QMessageLogger>
#include <QListWidgetItem>

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = 0);
    ~SettingsWindow();

private slots:
    void on_settingsList_itemActivated(QListWidgetItem *item);

private:
    Ui::SettingsWindow *ui;
    QMessageLogger     logger;

    bool eventFilter(QObject *object, QEvent *event);
    void loadSettingList();
    void loadSettingTabs(QString name);
};

#endif // SETTINGSWINDOW_H
