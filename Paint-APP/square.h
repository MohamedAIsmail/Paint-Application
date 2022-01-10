#ifndef SQUARE_H
#define SQUARE_H

#include "shapes.h"


#include "QWidget"
#include "QStyleOptionGraphicsItem"
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>

class Square : public Shapes
{

public:
    explicit Square(QPointF point,QObject *parent = 0);
    ~Square();


    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setLength(int newLength);
    void setWidth(int newWidth);


private:
    int length;
    int  width;

};

#endif // SQUARE_H
