#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    ui->settingsList->installEventFilter(this);
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

bool SettingsWindow::eventFilter(QObject *object, QEvent *event)
{
    if (object == ui->settingsList && event->type() == QEvent::Resize)
    {
        int spacerSize = ui->settingsList->width();

        ui->titleSpacer->changeSize(spacerSize + 10, 20);
        ui->titleWidget->layout()->invalidate();
    }

    return false;
}
