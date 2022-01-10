#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sortlist.h"

#include <algorithm>
#include <QtAlgorithms>
#include <QtWidgets>
#include <QList>
#include <QResizeEvent>
#include <QDebug>
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    scene = new PaintScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,100,100);


    QString SideBtnStyleSheet = "QPushButton{"
                                "font: 11pt Segoe UI;"
                                "color: rgb(255, 255, 255);"
                                "}"
                                "QPushButton:hover{"
                                "background-color: #4a505d"
                                "}";

            ui->sortAsButton->setStyleSheet(SideBtnStyleSheet);
            ui->sortDsButton->setStyleSheet(SideBtnStyleSheet);
            ui->SaveButton->setStyleSheet(SideBtnStyleSheet);
            ui->undoButton->setStyleSheet(SideBtnStyleSheet);
            ui->redoButton->setStyleSheet(SideBtnStyleSheet);
            ui->searchButton->setStyleSheet(SideBtnStyleSheet);

            ui->squareButton->setStyleSheet(SideBtnStyleSheet);
            ui->colorButton->setStyleSheet(SideBtnStyleSheet);
            ui->circleButton->setStyleSheet(SideBtnStyleSheet);
            ui->lineButton->setStyleSheet(SideBtnStyleSheet);
            ui->shapeNameBtn->setStyleSheet(SideBtnStyleSheet);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_colorButton_clicked()
{
    scene->penColor = QColorDialog::getColor(Qt::black);

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

}


void MainWindow::on_squareButton_clicked()
{
       scene->setTypeFigure(PaintScene::SquareType);
       n=ui->shapeName->text();
       bool exist=false;
       if(n==""){
           QMessageBox::about(this,"Paint","Please enter the shape name");
       }
       else{
           if(scene->vshapes.size()==0){
           scene->getShapeName(n);
           }
           else{

           for(int i=0; i<(int)(scene->vshapes.size());i++){

                if(n==scene->vshapes[i]->getName())
                {exist=true;}

          }
               if(exist)
               {
               QMessageBox::about(this,"Name","this name is already exist...try different name");
               }
               else{
                   scene->getShapeName(n);
                   }
            }
        }

}



void MainWindow::on_circleButton_clicked()
{
    scene->setTypeFigure(PaintScene::CircleType);
        n=ui->shapeName->text();

        bool exist=false;
        if(n==""){
            QMessageBox::about(this,"Paint","Please enter the shape name");
        }


        else{
            if(scene->vshapes.size()==0){
            scene->getShapeName(n);
            }



            else{

            for(int i=0; i<(int)( scene->vshapes.size());i++){

                 if(n==scene->vshapes[i]->getName())
                 {exist=true;}

           }
                if(exist)
                {
                QMessageBox::about(this,"Name","this name is already exist...try different name");


                }
                else{
                    scene->getShapeName(n);
                    }


             }


}
        n="";
}

void MainWindow::on_lineButton_clicked()
{
        scene->setTypeFigure(PaintScene::LineType);
        n=ui->shapeName->text();

        bool exist=false;
        if(n==""){
            QMessageBox::about(this,"Paint","Please enter the shape name");
        }


        else{
            if(scene->vshapes.size()==0){
            scene->getShapeName(n);
            }

            else{

            for(int i=0; i<(int)( scene->vshapes.size());i++){

                 if(n==scene->vshapes[i]->getName())
                 {exist=true;}

           }
                if(exist)
                {
                QMessageBox::about(this,"Name","this name is already exist...try different name");


                }
                else{
                    scene->getShapeName(n);
                    }


             }
        }

}


void MainWindow::on_searchButton_clicked()
{
     n=ui->searchName->text();


     if(n==""){
         QMessageBox::about(this,"Paint","Please enter tha shape name");
     }
     else{

     bool exist=false;


   for(int i=0; i<(int)(scene->vshapes.size());i++){
       if(n==scene->vshapes[i]->getName())
       {
           ui->infoname->setText(scene->vshapes[i]->getName());
           ui->infoper->setText(QString::number(scene->vshapes[i]->perimeter()));
           ui->infoColor->setText(scene->vshapes[i]->getColor().name());
           exist=true;
       }

   }


   if(!exist)
   {
      QMessageBox::about(this,"Shape","Doesn't exit");
   }

}
}


void MainWindow::on_redoButton_clicked()
{
    if (scene->vundo.size()!=0){
    scene->vshapes.emplace_back(scene->vundo[scene->vundo.size()-1]);
    scene->vundo.pop_back();}

    scene->undoStack->redo();
}


void MainWindow::on_undoButton_clicked()
{
    if(scene->vshapes.size()==0)
    {
       QMessageBox::about(this,"Paint","No shapes");
    }
else{
    scene->vundo.emplace_back(scene->vshapes[scene->vshapes.size()-1]);
    scene->vshapes.pop_back();
    scene->undoStack->undo();
    }

}


void MainWindow::saveAsBitmap() {
    saveDrawing("png");
}
void MainWindow::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
           return;

       // Create a new image to display and fill it with white
       QImage newImage(newSize, QImage::Format_RGB32);
newImage.fill(qRgb(255, 255, 255));

       // Draw the image
       QPainter painter(&newImage);
       painter.drawImage(QPoint(0, 0), *image);
       *image = newImage;
}
bool MainWindow::saveImage(const QString &filename, const char *fileformat)
{


        const QPixmap pixmap = ui->graphicsView->grab();
        const QString fileName("/home/pw/image.png");
        qDebug() << pixmap.save(fileName);

        if (pixmap.save(filename, fileformat)) {
           changed = false;
           return true;
        } else {
            return false;
        }
        // QImage visibleImage = image;
         //resizeImage(scene, size());

         //if (visibleImage.save(filename, fileformat)) {
           //  changed = false;
           //  return true;
       //  } else {
           //  return false;
        // }

}


bool MainWindow::saveDrawing(const QByteArray &fileFormat) {
    QString currentPath = QDir::currentPath() + "/painter." + fileFormat;

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), currentPath,
              tr("%1 Files (*.%2;;All Files (*)").arg(QString::fromLatin1(fileFormat.toUpper()))
                                                  .arg(QString::fromLatin1(fileFormat)));

    if (fileName.isEmpty()) {
        return false;
    }else {
        return saveImage(fileName, fileFormat.constData());
    }
}

bool MainWindow::trySave() {
    // check for unsaved changes when we click at X button to close the paint
    if (isChanged()) {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("Painter"),
                         tr("Your drawing has been modified.\n"
                            "Would you like to save your changes?"),
                         QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
       if (ret == QMessageBox::Save) {
           return saveDrawing("png");
       }
       else if (ret == QMessageBox::Cancel) {
           return false;
       }
    }
    return true;
}



void MainWindow::on_SaveButton_clicked()
{
  saveAsBitmap();
}
void MainWindow::closeEvent (QCloseEvent *event)
{
    trySave();
}

void MainWindow::on_sortAsButton_clicked()
{
    if ((int)(scene->vshapes.size())==0){
         QMessageBox::about(this,"Paint","No shapes found");
    }
    else {
        SORTLIST AS;
        AS.tabledisplay((int)(scene->vshapes.size()));


       for(int i=0 ; i<(int)(scene->vshapes.size()) ; i++){
          scene->objects.emplace_back(scene->vshapes[i]->perimeter());
       }

       std::sort(scene->objects.begin(),scene->objects.end());

         for(int j=0; j<(int)(scene->objects.size());j++){
             for(int i=0; i<(int)(scene->vshapes.size());i++){

               if (scene->objects[j] == scene->vshapes[i]->perimeter()){
                   AS.info(j, scene->vshapes[i]->getName(), scene->vshapes[i]->perimeter() , scene->vshapes[i]->getColor().name() );
                 }


   }
}

         AS.setModal(true);
         AS.exec();
    }
    scene->objects.clear();
}


void MainWindow::on_sortDsButton_clicked()
{
    if ((int)(scene->vshapes.size())==0){
         QMessageBox::about(this,"Paint","No shapes found");
    }
    else {
          SORTLIST DS;
          DS.tabledisplay((int)(scene->vshapes.size()));

       for(int i=0 ; i<(int)(scene->vshapes.size()) ; i++){
          scene->objects.emplace_back(scene->vshapes[i]->perimeter());
       }

       std::sort(scene->objects.rbegin(),scene->objects.rend());

         for(int j=0 ; j<(int)(scene->objects.size()) ; j++){
             for(int i=0; i<(int)(scene->vshapes.size());i++){

               if (scene->objects[j] == scene->vshapes[i]->perimeter()){
                    DS.info(j, scene->vshapes[i]->getName(),scene->vshapes[i]->perimeter() , scene->vshapes[i]->getColor().name() );
                 }
              }
        }
          DS.setModal(true);
          DS.exec();
    }
    scene->objects.clear();
}


