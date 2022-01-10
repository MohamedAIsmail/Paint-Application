#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "square.h"
#include "shapes.h"
#include "circle.h"
#include "line.h"
#include "commands.h"
#include "sortlist.h"
#include "paintscene.h"


#include <QMainWindow>
#include <QtGui>
#include <QDialog>
#include <QtCore>
#include <QCompleter>
#include <QGraphicsScene>
#include<QVector>
#include<QUndoCommand>
#include<QUndoStack>
#include<QCloseEvent>
#include<QStack>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool isChanged() const { return changed; }

    bool saveImage(const QString &filename, const char *fileformat);



private:
    Ui::MainWindow *ui;
    PaintScene *scene;
    Shapes *shape;
    Square *square;
    Circle *circle;
    Line *line;
    QPen pen;
    QColor color;
    QUndoStack *undoStack = nullptr;
    QImage image;
    QImage backupImage;
    bool changed;


    QString l,w,n;

    QString x1,x2,y1,y2;







    void resizeEvent(QResizeEvent *event);


private slots:
void closeEvent (QCloseEvent *event);
    void on_colorButton_clicked();
    void on_squareButton_clicked();
    void on_circleButton_clicked();
    void on_lineButton_clicked();
    void on_searchButton_clicked();
    void on_redoButton_clicked();
    void on_undoButton_clicked();
    void resizeImage(QImage *image, const QSize &newSize);
void saveAsBitmap() ;
    bool trySave();
    bool saveDrawing(const QByteArray &fileFormat);

    void on_SaveButton_clicked();
    void on_sortAsButton_clicked();
    void on_sortDsButton_clicked();
};
#endif // MAINWINDOW_H
