#ifndef STRIKELINE_H
#define STRIKELINE_H

#include <QQuickItem>

class StrikeLine : public QQuickItem
{
    Q_OBJECT
public:
    StrikeLine();

protected:
    QSGNode *updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *);
};

#endif // STRIKELINE_H
