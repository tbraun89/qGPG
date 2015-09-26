#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>

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

private:
    Settings();
    Settings(const Settings&);
    Settings& operator = (const Settings&);
};

#endif // SETTINGS_H
