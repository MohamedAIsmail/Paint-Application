#include "square.h"

Square::Square(QPointF point, QObject *parent) : Shapes(point,parent)
{
}

Square::~Square()
{

}

QRectF Square::boundingRect() const
{
 return QRectF(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
                        endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
                        qAbs(endPoint().x()- startPoint().x()),
                        qAbs(endPoint().y()- startPoint().y()));
}


void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QRectF rect= boundingRect();
    QLineF l(rect.bottomLeft().x(),rect.bottomLeft().y(),rect.bottomRight().x(),rect.bottomRight().y());
    QLineF w(rect.topLeft().x(),rect.topLeft().y(),rect.bottomLeft().x(),rect.bottomLeft().y());

    length = l.length();
    width = w.length();
    setS((length+width)*2);

    painter->setPen(shapeColor);
    painter->drawRect(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Square::setLength(int newLength)
{
 length = newLength;
}

void Square::setWidth(int newWidth)
{
 width = newWidth;
}
