#ifndef ADDNEW_H
#define ADDNEW_H

#include <QWidget>
#include "QModelIndexList"
#include "QSqlQueryModel"
namespace Ui {
class addnew;
}

class addnew : public QWidget
{
    Q_OBJECT

public:
    explicit addnew(QWidget *parent = nullptr);
    ~addnew();
    void showList(QString,QString,QString);



private slots:









void on_tableView_clicked(const QModelIndex &index);

void on_lineEdit_textEdited(const QString &arg1);

void on_lineEdit_2_textEdited(const QString &arg1);

void on_lineEdit_3_textEdited(const QString &arg1);

void on_pushButton_clicked();

void on_pushButton_2_clicked();


void on_pushButton_3_clicked();



private:
    Ui::addnew *ui;
    QSqlQueryModel * List1= new QSqlQueryModel();
    QSqlQueryModel * List2= new QSqlQueryModel();
    QSqlQueryModel * List3= new QSqlQueryModel();
};

#endif // ADDNEW_H
