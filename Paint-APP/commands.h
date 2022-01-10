#ifndef COMMANDS_H
#define COMMANDS_H

#include<QUndoCommand>
#include<QGraphicsScene>
#include<shapes.h>

class AddCommand : public QUndoCommand
{

public:

    AddCommand(Shapes *item, QGraphicsScene *scene,
               QUndoCommand *parent = nullptr);

    ~AddCommand();

    void undo() override;
    void redo() override;
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent (QGraphicsSceneMouseEvent *event);



private:

    Shapes *myItem;
    Shapes *temp;
    QGraphicsScene *myGraphicsScene;
};

#endif // COMMANDS_H


