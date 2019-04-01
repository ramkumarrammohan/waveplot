#include "strikeline.h"

#include <QSGGeometryNode>
#include <QSGGeometry>
#include <QSGFlatColorMaterial>

StrikeLine::StrikeLine()
{
    setFlag(ItemHasContents, true);
}

QSGNode *StrikeLine::updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *)
{
    QSGGeometryNode *node = nullptr;

    QSGGeometry *geometry;
    QSGFlatColorMaterial *material;
    node = static_cast<QSGGeometryNode *>(oldNode);
    if(!node) {
        node = new QSGGeometryNode;
        geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 2);

        geometry->setDrawingMode(GL_LINES);
        geometry->setLineWidth(1);

        material = new QSGFlatColorMaterial;
        material->setColor(QColor(255, 0, 0));

        node->setGeometry(geometry);
        node->setFlag(QSGNode::OwnsGeometry);
        node->setMaterial(material);
        node->setFlag(QSGNode::OwnsMaterial);
    } else {
        geometry = node->geometry();
        material = static_cast<QSGFlatColorMaterial *>(node->material());
    }

    geometry->vertexDataAsPoint2D()[0].set(0, height());
    geometry->vertexDataAsPoint2D()[1].set(width(), 0);
    node->markDirty(QSGNode::DirtyGeometry);

    return node;
}
