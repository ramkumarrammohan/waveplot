#include "waveform.h"
#include "sawtoothgenerator.h"
#include "common.h"

#include <QSGGeometryNode>
#include <QSGGeometry>
#include <QSGFlatColorMaterial>


static const int POINTS = 1000;

Waveform::Waveform()
{
    setFlag(ItemHasContents, true);

    _generator = new SawtoothGenerator;
}

QSGNode *Waveform::updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *)
{
    QSGGeometryNode *node = nullptr;

    QSGGeometry *geometry;
    QSGFlatColorMaterial *material;
    node = static_cast<QSGGeometryNode *>(oldNode);
    if(!node) {
        node = new QSGGeometryNode;
        geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), POINTS*2);

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

    for (int i = 0; i < POINTS; i+=2) {
        Point pt = _generator->getPlot();
//        qDebug() << QString("[%1, {%2, %3}]").arg(pt.x).arg(pt.y1).arg(pt.y2);

        geometry->vertexDataAsPoint2D()[i].set(pt.x, pt.y1);
        geometry->vertexDataAsPoint2D()[i+1].set(pt.x, pt.y2);
    }

    node->markDirty(QSGNode::DirtyGeometry);

    return node;
}
