#ifndef EDITACCOUNTS_H
#define EDITACCOUNTS_H

#include <QWidget>

namespace Ui {
class editaccounts;
}

class editaccounts : public QWidget
{
    Q_OBJECT

public:
    explicit editaccounts(QString,QString,QString,QString,QWidget *parent = nullptr);
    ~editaccounts();
    QString Code_for_edit;
private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();
    void closeEvent(QCloseEvent *event);
private:
    Ui::editaccounts *ui;
};

#endif // EDITACCOUNTS_H
