#include "settings.h"

const QString Settings::ORGANIZATION_NAME = "qGPG";
const QString Settings::APPLICATION_NAME  = "qGPG";

Settings::Settings() {}
Settings::~Settings() {}

void Settings::saveWidgetProperty(QWidget* widget, const char* property)
{
    QString key   = widgetKey(widget, property);
    QString value = widget->property(property).toString();

    settings.setValue(key, value);
    logger.debug(QString("saveWidgetProperty => %1 = \"%2\"").arg(key, value).toStdString().c_str());
}

QVariant Settings::loadWidgetProperty(QWidget *widget, const char *property)
{
    QString key   = widgetKey(widget, property);

    return settings.value(key).toString();
}

QString Settings::widgetKey(QWidget *widget, const char *property)
{
    return QString("widgets/%1/%2").arg(widget->objectName(), property);
}
