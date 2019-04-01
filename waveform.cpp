#include "waveform.h"

#include <QSGGeometryNode>
#include <QSGGeometry>
#include <QSGFlatColorMaterial>

Waveform::Waveform()
{
    setFlag(ItemHasContents, true);
}

QSGNode *Waveform::updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *)
{
    return oldNode;
}
