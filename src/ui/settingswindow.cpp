#include "settingswindow.h"
#include "ui_settingswindow.h"

#include <QVector>

SettingsWindow::SettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    ui->settingsList->installEventFilter(this);
    loadSettingList();
    loadSettingTabs(tr("qGPG"));

    // TODO save & load window state
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

void SettingsWindow::loadSettingList()
{
    QListWidgetItem *qgpgSettings = new QListWidgetItem(QIcon(":/icons/qgpg_settings"), tr("qGPG"));
    ui->settingsList->addItem(qgpgSettings);
    ui->settingsList->setCurrentRow(0);
}

void SettingsWindow::on_settingsList_itemActivated(QListWidgetItem *item)
{
    for (int i = 0; i >= ui->settingsTab->count(); i++)
        ui->settingsTab->removeTab(0);

    loadSettingTabs(item->text());
}

void SettingsWindow::loadSettingTabs(QString name)
{
    logger.debug(QString("Load settings for %1.").arg(name).toStdString().c_str());

    if (name == "qGPG")
    {
        // TODO load tabs for qGPG
    }
}
