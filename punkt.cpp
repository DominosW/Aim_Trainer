#include "punkt.h"
#include <QGraphicsPixmapItem>
#include <QDebug>

Punkt::Punkt()
{
    setPixmap(QPixmap(":/aim.png"));
}

void Punkt::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Dobry strzał";

    emit mousePressSignal();
}
