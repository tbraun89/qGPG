#ifndef INITIALIZEINTERFACE_H
#define INITIALIZEINTERFACE_H

// TODO remove this interface use "QJsonObject QPluginLoader::metaData() const"

#include <QtPlugin>
#include <QString>

class InitializeInterface
{
public:
    virtual ~InitializeInterface() {}
    virtual QString test() = 0;
};

#define InitializeInterface_iid "qGPG.plugin.InitializeInterface"

Q_DECLARE_INTERFACE(InitializeInterface, InitializeInterface_iid)

#endif // INITIALIZEINTERFACE_H
