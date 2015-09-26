#include "errorlog.h"
#include "ui_errorlog.h"

#include "settings/settings.h"

#include <QHideEvent>

ErrorLog::ErrorLog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ErrorLog)
{
    ui->setupUi(this);
    loadSettings();
}

ErrorLog::~ErrorLog()
{
    delete ui;
}

void ErrorLog::addError(QtMsgType type, QString msg)
{
    QListWidgetItem *errorMessage = new QListWidgetItem(msg);

    switch (type) {
    case QtDebugMsg:
        errorMessage->setBackgroundColor(Qt::white);
        break;
    case QtWarningMsg:
        errorMessage->setBackgroundColor(Qt::gray);
        break;
    case QtCriticalMsg:
        errorMessage->setBackgroundColor(Qt::red);
        break;
    case QtFatalMsg:
        errorMessage->setBackgroundColor(Qt::darkRed);
        break;
    }

    ui->errorList->addItem(errorMessage);
}

void ErrorLog::on_clodeButton_clicked()
{
    hide();
}

void ErrorLog::hideEvent(QHideEvent *event)
{
    saveSettings();
    event->accept();
}

void ErrorLog::saveSettings()
{
    Settings& settings = Settings::instance();

    settings.saveWidgetProperty(this, "x");
    settings.saveWidgetProperty(this, "y");
    settings.saveWidgetProperty(this, "width");
    settings.saveWidgetProperty(this, "height");
}

void ErrorLog::loadSettings()
{
    Settings& settings = Settings::instance();
    int x              = settings.loadWidgetProperty(this, "x").toInt();
    int y              = settings.loadWidgetProperty(this, "y").toInt();
    int width          = settings.loadWidgetProperty(this, "width").toInt();
    int height         = settings.loadWidgetProperty(this, "height").toInt();

    if (x && y)
        move(x, y);

    if (width && height)
        resize(width, height);
}
