#ifndef CIRCLE_H
#define CIRCLE_H

#include "shapes.h"



#include "QWidget"
#include "QStyleOptionGraphicsItem"
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>

class Circle : public Shapes
{


public:

    explicit Circle(QPointF point,QObject *parent = 0);
    ~Circle();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


    void setRadius(int newRadius);

    int getRadius();



private:
    int radius;

};

#endif // CIRCLE_H
