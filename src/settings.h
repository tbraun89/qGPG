#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QWidget>
#include <QMessageLogger>
#include <QSettings>

class Settings
{
public:
    static const QString ORGANIZATION_NAME;
    static const QString ORGANIZATION_DOMAIN;
    static const QString APPLICATION_NAME;

    static Settings& instance()
    {
        static Settings myInstance;
        return myInstance;
    }
    ~Settings();

    void saveWidgetProperty(QWidget* widget, const char* property);

private:
    Settings();
    Settings(const Settings&);
    Settings& operator = (const Settings&);

    QSettings      settings;
    QMessageLogger logger;
};

#endif // SETTINGS_H
