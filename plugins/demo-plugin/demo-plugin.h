#ifndef DEMOPLUGIN_H
#define DEMOPLUGIN_H

#include <QObject>
#include <QtPlugin>

#include "plugin/initializeinterface.h"

class DemoPlugin : public QObject, InitializeInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID InitializeInterface_iid)
    Q_INTERFACES(InitializeInterface)

public:
    QString test() Q_DECL_OVERRIDE;
};

#endif // DEMOPLUGIN_H
