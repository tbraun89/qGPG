#include "settings.h"

#include <QVariant>

const QString Settings::ORGANIZATION_NAME   = "tbraun";
const QString Settings::ORGANIZATION_DOMAIN = "github.com/tbraun89/qGPG";
const QString Settings::APPLICATION_NAME    = "qGPG";

Settings::Settings() {}
Settings::~Settings() {}

void Settings::saveWidgetProperty(QWidget* widget, const char* property)
{
    QString key   = QString("widget/%1/%2").arg(widget->objectName(), property);
    QString value = widget->property(property).toString();

    settings.setValue(key, value);
    logger.debug(QString("saveWidgetProperty => %1 = \"%2\"").arg(key, value).toStdString().c_str());
}
