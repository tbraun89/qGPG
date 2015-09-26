#ifndef TOOLBARINTERFACE_H
#define TOOLBARINTERFACE_H

#include <QVector>
#include <QAction>

class ToolbarInterface
{
public:
    virtual ~ToolbarInterface() {}

    virtual QVector<QAction> toolbarActions() = 0;
};

#define ToolbarInterface_iid "qGPG.plugin.ToolbarInterface"

Q_DECLARE_INTERFACE(ToolbarInterface, ToolbarInterface_iid)

#endif // TOOLBARINTERFACE_H
