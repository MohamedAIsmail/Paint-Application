#include "line.h"
#include <cmath>
Line::Line(QPointF point, QObject *parent): Shapes(point,parent)
{

}

Line::~Line()
{

}

QRectF Line::boundingRect() const
{
    return QRectF(0,0,0,0);
}

QLineF Line::setLine() const
{
    return QLineF(startPoint().x(),startPoint().y(),endPoint().x(),endPoint().y());
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QLineF line = setLine();
    setS(line.length());

    painter->setPen(shapeColor);
    painter->drawLine(line);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

float Line::getLineLength() const
{
    return lineLength;
}




