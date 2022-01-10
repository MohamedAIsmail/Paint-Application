#ifndef SHAPES_H
#define SHAPES_H


#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>

class Shapes : public QObject , public QGraphicsItem
{

    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
    // The property is the starting point, which draw the shape
    Q_PROPERTY(QPointF startPoint
                  READ startPoint WRITE setStartPoint
                  NOTIFY pointChanged)
       // The property is the endpoint, which draw the shape
    Q_PROPERTY(QPointF endPoint
                  READ endPoint WRITE setEndPoint
                  NOTIFY pointChanged)
public:
    explicit Shapes(QPointF point,QObject *parent = 0);
    ~Shapes();



    const QColor &getColor() const;
    void setColor(const QColor &newColor);

    void setName(QString n);
    QRectF boundingRect() const;

    QPointF startPoint() const;
    QPointF endPoint() const;

    QString getName();
    float perimeter();
    void setS(float m);
    void setStartPoint(const QPointF point);
    void setEndPoint(const QPointF point);
    void updateShape();

signals:
    void pointChanged();

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);



    QColor shapeColor = Qt::black;
    QPen pen;
    bool pressed;


private:
    QPointF m_startPoint;
    QPointF m_endPoint;
    QString name;
    float s;

};

#endif // SHAPES_H
