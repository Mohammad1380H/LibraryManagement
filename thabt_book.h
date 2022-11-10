#ifndef THABT_BOOK_H
#define THABT_BOOK_H

#include <QWidget>
#include "QSqlQueryModel"
#include "QString"
namespace Ui {
class thabt_book;
}

class thabt_book : public QWidget
{
    Q_OBJECT

public:
    explicit thabt_book(QWidget *parent = nullptr);
    ~thabt_book();
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
    Ui::thabt_book *ui;
    QSqlQueryModel * List1= new QSqlQueryModel();

};

#endif // THABT_BOOK_H
