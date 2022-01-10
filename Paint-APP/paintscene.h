#ifndef PAINTSCENE_H
#define PAINTSCENE_H
#include <QPen>
#include<QPaintEvent>
#include <QPainter>
#include <QColor>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QUndoCommand>
#include <QMessageBox>

#include "shapes.h"
#include "square.h"
#include "circle.h"
#include "line.h"
#include "commands.h"


class PaintScene : public QGraphicsScene
{
    Q_OBJECT
     Q_PROPERTY(int typeFigure
                 READ typeFigure WRITE setTypeFigure
                 NOTIFY typeFigureChanged)
public:
    PaintScene(QObject *parent =0);
    ~PaintScene();

    Square *square;
    Circle *circle;
    Line *line;
    QUndoStack *undoStack = nullptr;
    QMessageBox msgBox;
    bool nameFalse;

    int typeFigure() const;
    void setTypeFigure(const int type);

    enum ShapeTypes {
            SquareType,
            LineType,
            CircleType
        };

    QColor penColor;
    std::vector<std::shared_ptr<Shapes>> vshapes;
    std::vector <float> objects;
    std::vector<std::shared_ptr<Shapes>> vundo;

    void getShapeName(QString n);

signals:
    void typeFigureChanged();

private:
    Shapes *temp;
    QString name;
    int m_typeShape;

        void mousePressEvent(QGraphicsSceneMouseEvent * event);
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
        void mouseReleaseEvent (QGraphicsSceneMouseEvent *event);
};

#endif // PAINTSCENE_H
