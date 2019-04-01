#ifndef WAVEFORM_H
#define WAVEFORM_H

#include <QQuickItem>

class Waveform : public QQuickItem
{
    Q_OBJECT
public:
    Waveform();

protected:
    QSGNode *updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *);
};

#endif // WAVEFORM_H
