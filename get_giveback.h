#ifndef GET_GIVEBACK_H
#define GET_GIVEBACK_H

#include <QWidget>
#include "Books.hpp"
#include "manage_all_books.hpp"
#include "Users.hpp"
namespace Ui {
class get_giveback;
}

class get_giveback : public QWidget
{
    Q_OBJECT

public:
    explicit get_giveback(QWidget *parent = nullptr);
    ~get_giveback();
    QSqlQueryModel * List1= new QSqlQueryModel();
    QSqlQueryModel * List2= new QSqlQueryModel();
    QSqlQueryModel * List3= new QSqlQueryModel();
    void showList(QString,QString);
    int default_number=4;

    void show_status(const QModelIndex &index);
private slots:






    void on_pushButton_clicked();

    void on_pushButton_2_clicked(bool tamdid=false);

    void on_pushButton_5_clicked(bool tamdid=false);

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::get_giveback *ui;
};

#endif // GET_GIVEBACK_H
