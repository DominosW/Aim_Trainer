#ifndef REAKCJA_H
#define REAKCJA_H

#include <QGraphicsRectItem>

class Reakcja : public QGraphicsRectItem
{
public:
    Reakcja();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // REAKCJA_H
