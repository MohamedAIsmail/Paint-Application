#include "circle.h"


Circle::Circle(QPointF point,QObject *parent): Shapes(point,parent)
{

}

Circle::~Circle()
{

}

QRectF Circle::boundingRect() const
{
    return QRectF(0,0,radius,radius);
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        radius = abs(sqrt(pow(endPoint().x()-startPoint().x(),2)+pow(endPoint().y()-startPoint().y(),2)));
        painter->setPen(shapeColor);
        painter->drawEllipse(startPoint().x(),endPoint().y(),radius,radius);

        setS(radius*2*3.14);



    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Circle::setRadius(int newRadius)
{
    radius = newRadius;
}



int Circle::getRadius(){return radius;}
