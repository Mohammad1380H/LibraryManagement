#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QWidget>
#include "QModelIndexList"
#include "QSqlQueryModel"
namespace Ui {
class addbook;
}

class addbook : public QWidget
{
    Q_OBJECT

public:
    explicit addbook(QWidget *parent = nullptr);
    ~addbook();


private slots:
    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::addbook *ui;
    QSqlQueryModel * List1= new QSqlQueryModel();
    QSqlQueryModel * List2= new QSqlQueryModel();
    void showList(QString,QString);

};

#endif // ADDBOOK_H
