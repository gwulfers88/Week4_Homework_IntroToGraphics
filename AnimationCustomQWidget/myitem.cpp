#include "myitem.h"

MyItem::MyItem()
{
    //Random start rotation
    angle = (qrand() % 360);
    setRotation(angle);

    //Set the speed
    speed = 5;

    //random start point
    int startX = 0;
    int startY = 0;

    if(qrand() % 1)
    {
        startX = qrand() % 200;
        startY = qrand() % 200;
    }
    else
    {
        startX = qrand() % -100;
        startY = qrand() % -100;
    }

    setPos(mapToParent(startX, startY));
}

QRectF MyItem::boundingRect() const
{
    return QRect(0, 0, 20, 20);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();

    //basic collision detection
    if(scene()->collidingItems(this).isEmpty())
    {
        //No Collision
        QPen pen(Qt::green, 5);
        painter->setPen(pen);
    }
    else
    {
        //collsion
        QPen pen(Qt::red, 5);
        painter->setPen(pen);

        //Set the position
        doCollision();
    }

    painter->drawEllipse(rect);
}

void MyItem::advance(int phase)
{
    if(!phase) return;

    QPointF loc = this->pos();
    setPos(mapToParent(0, -speed));
}

void MyItem::doCollision()
{
    //Get new pos
    //Change angle with randomnexx
    if(qrand() % 1)
    {
        setRotation(rotation() + 180 + qrand() % 10);
    }
    else
    {
        setRotation(rotation() + 180 + qrand() % -10);
    }

    //check if new pos is in bounds
    QPointF newPos = mapToParent(-(boundingRect().width()),
                                 -(boundingRect().width() + 2));
    if(!scene()->sceneRect().contains(newPos))
    {
        //Move back in bounds
        newPos = mapToParent(0, 0);
    }
    else
    {
        //Set the new pos
        setPos(newPos);
    }
}



