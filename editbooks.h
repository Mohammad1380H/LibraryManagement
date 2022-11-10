#ifndef EDITBOOKS_H
#define EDITBOOKS_H

#include <QWidget>
#include "QSqlQueryModel"
namespace Ui {
class editbooks;
}

class editbooks : public QWidget
{
    Q_OBJECT

public:
    explicit editbooks(QString,QString,QString,QString,QString,QWidget *parent = nullptr);
    ~editbooks();
    QString Old_Code_Book;
    void showList_pub(QString);
    void showList_wrt(QString);
    void showList_trs(QString);
    QString Separation(QString);

private slots:
    void on_pushButton_4_clicked();

    void on_lineEdit_11_textEdited(const QString &arg1);

    void on_lineEdit_10_textEdited(const QString &arg1);

    void on_lineEdit_8_textEdited(const QString &arg1);

    void on_pushButton_clicked();
    void closeEvent(QCloseEvent *event);


private:
    Ui::editbooks *ui;
    QSqlQueryModel * List1= new QSqlQueryModel();
};

#endif // EDITBOOKS_H
