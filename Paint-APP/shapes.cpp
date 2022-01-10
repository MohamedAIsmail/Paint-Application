#include "shapes.h"


Shapes::Shapes(QPointF point,QObject *parent)
{
    pressed=false;
    setFlag(ItemIsMovable);

    this->setStartPoint(mapFromScene(point));
    this->setEndPoint(mapFromScene(point));

    connect(this, &Shapes::pointChanged, this, &Shapes::updateShape);
    Q_UNUSED(parent)


}

Shapes::~Shapes()
{

}

const QColor &Shapes::getColor() const
{
    return shapeColor;
}

void Shapes::setColor(const QColor &newColor)
{
    shapeColor = newColor;
}

void Shapes::setName(QString n){
    name=n;
}


QString Shapes::getName(){
    return name;
}


float Shapes::perimeter(){
    return s ;
}


void Shapes::setS(float m){
    s=m;
}


void Shapes::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    pressed=true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Shapes::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    pressed=false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}


QRectF Shapes::boundingRect() const
{
    return QRectF((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                      (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                      qAbs(endPoint().x() - startPoint().x()) + 10,
                      qAbs(endPoint().y() - startPoint().y()) + 10);

}

void Shapes::updateShape()
{
    // Call update area in which the figure lies
    this->update((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                 (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                 qAbs(endPoint().x() - startPoint().x()) + 10,
                 qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Shapes::setStartPoint(const QPointF point)
{
    m_startPoint = mapFromScene(point);
    emit pointChanged();
}

void Shapes::setEndPoint(const QPointF point)
{
    m_endPoint = mapFromScene(point);
    emit pointChanged();
}

QPointF Shapes::startPoint() const
{
    return m_startPoint;
}

QPointF Shapes::endPoint() const
{
    return m_endPoint;
}


