#ifndef SORTLIST_H
#define SORTLIST_H

#include <QDialog>
#include <QTableWidget>

namespace Ui {
class SORTLIST;
}

class SORTLIST : public QDialog
{
    Q_OBJECT

public:
    QTableWidget *table= new QTableWidget(this);

    explicit SORTLIST(QWidget *parent = nullptr);
    ~SORTLIST();
    void tabledisplay(int x);
    void setrow(QTableWidget* y ,int x);
    void info (int x , QString name , float perimeter , QString color);


private:
Ui::SORTLIST *ui;
};

#endif // SORTLIST_H
