#include "sortlist.h"
#include "ui_sortlist.h"
#include "shapes.h"
#include "mainwindow.h"

#include<QVector>
#include <QTableWidget>

SORTLIST::SORTLIST(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SORTLIST)
{
    ui->setupUi(this);


}

SORTLIST::~SORTLIST()
{
    delete ui;
}



void SORTLIST:: tabledisplay(int x){
    table->setMaximumWidth(317);
    table->setMinimumWidth(317);
    table->setMaximumHeight(500);
    table->setMinimumHeight(500);
    setrow(table , x);
    table->setColumnCount(3);
    QStringList hlabels;
    hlabels << "Name" << "Perimeter" << "Color" ;
    table->setHorizontalHeaderLabels(hlabels);
}

void SORTLIST::setrow(QTableWidget* y ,int x){
    y->setRowCount(x);
}

void SORTLIST::  info (int x ,QString name , float perimeter , QString color)
{
    QTableWidgetItem *itemn = new QTableWidgetItem ;
    QTableWidgetItem *itemp = new QTableWidgetItem ;
    QTableWidgetItem *itemc = new QTableWidgetItem ;

             itemn->setText( name );
             table->setItem(x , 0 , itemn);

             itemp->setText( QString::number(perimeter) );
             table->setItem(x , 1 , itemp);

             itemc->setText( color );
             table->setItem(x , 2 , itemc);

}

