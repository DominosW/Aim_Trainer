#include "reakcja.h"
#include <QGraphicsRectItem>
#include <QDebug>

Reakcja::Reakcja()
{
    setRect(0,0,100,100);
}

void Reakcja::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Naciśnięcie myszy";
}
