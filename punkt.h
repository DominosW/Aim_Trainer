#ifndef PUNKT_H
#define PUNKT_H
#include <QGraphicsPixmapItem>

class Punkt : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Punkt();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void mousePressSignal();
};

#endif // PUNKT_H
