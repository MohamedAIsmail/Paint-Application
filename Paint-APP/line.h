#ifndef LINE_H
#define LINE_H
#include "shapes.h"

#include <QWidget>
#include <QtCore>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsLineItem>
#include <QPainter>

#include <QDebug>
#include <QLine>

class Line : public Shapes
{

public:

    explicit Line(QPointF point,QObject *parent = 0);
    ~Line();

    QLineF setLine() const;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    float getLineLength() const;
    void setLineLength();





private:
    float lineLength;


};

#endif // LINE_H
