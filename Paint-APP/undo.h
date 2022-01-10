#ifndef UNDO_H
#define UNDO_H

#include <QUndoStack>
#include <QUndoCommand>
#include <mainwindow.h>

class Undo : public QUndoCommand
{

public:
    Undo(QUndoCommand *parent = nullptr);
    ~Undo();

    void undo() override;
    void redo() override;


};

#endif // UNDO_H
