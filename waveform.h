#ifndef WAVEFORM_H
#define WAVEFORM_H

#include <QQuickItem>

class SawtoothGenerator;

class Waveform : public QQuickItem
{
    Q_OBJECT
public:
    Waveform();

protected:
    QSGNode *updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *);

private:
    SawtoothGenerator *_generator;

};

#endif // WAVEFORM_H
