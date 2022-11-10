#ifndef QUERIES_H
#define QUERIES_H

#include <QWidget>
#include "QSqlQueryModel"
namespace Ui {
class queries;
}

class queries : public QWidget
{
    Q_OBJECT

public:
    explicit queries(QString,QWidget *parent = nullptr);
    ~queries();
    QSqlQueryModel * List1= new QSqlQueryModel();
    QSqlQueryModel * List2= new QSqlQueryModel();
    QSqlQueryModel * List3= new QSqlQueryModel();
    QString Code_book_for_query= "";

private slots:


    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::queries *ui;
};

#endif // QUERIES_H
