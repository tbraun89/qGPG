#ifndef DEMOPLUGIN_H
#define DEMOPLUGIN_H

#include "plugin/toolbarinterface.h"

#include <QObject>
#include <QtPlugin>
#include <QVector>
#include <QAction>

class DemoPlugin : public QObject, ToolbarInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID ToolbarInterface_iid FILE "demo-plugin.json")
    Q_INTERFACES(ToolbarInterface)

public:
    QVector<QAction *> toolbarActions() Q_DECL_OVERRIDE;
};

#endif // DEMOPLUGIN_H
