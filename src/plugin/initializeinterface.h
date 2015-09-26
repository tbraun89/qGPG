#ifndef INITIALIZEINTERFACE_H
#define INITIALIZEINTERFACE_H

#include "pluginloader.h"

#include <QtPlugin>

class InitializeInterface
{
public:
    virtual ~InitializeInterface() {}
    virtual PluginLoader::PluginDefinition getPluginDefinition();
};

#define InitializeInterface_iid "qGPG.plugin.InitializeInterface"

Q_DECLARE_INTERFACE(InitializeInterface, InitializeInterface_iid)

#endif // INITIALIZEINTERFACE_H
