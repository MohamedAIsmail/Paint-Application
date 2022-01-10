#include "commands.h"




AddCommand::AddCommand(Shapes *item, QGraphicsScene *scene, QUndoCommand *parent){
    myGraphicsScene = scene;
    myItem = item;

}


AddCommand::~AddCommand()
{

}

void AddCommand::undo()
{
    myGraphicsScene->removeItem(myItem);
    myGraphicsScene->update();
}

void AddCommand::redo()
{
    myGraphicsScene->addItem(myItem);
    myGraphicsScene->update();
    myGraphicsScene->clearSelection();

}



