#ifndef ADDACCOUNT_H
#define ADDACCOUNT_H

#include <QWidget>

namespace Ui {
class addaccount;
}

class addaccount : public QWidget
{
    Q_OBJECT

public:
    explicit addaccount(QWidget *parent = nullptr);
    ~addaccount();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void closeEvent(QCloseEvent *event);

private:
    Ui::addaccount *ui;
};

#endif // ADDACCOUNT_H
