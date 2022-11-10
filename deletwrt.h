#ifndef DELETWRT_H
#define DELETWRT_H

#include <QWidget>

namespace Ui {
class deletwrt;
}

class deletwrt : public QWidget
{
    Q_OBJECT

public:
    explicit deletwrt(QWidget *parent = nullptr);
    ~deletwrt();

private slots:
    void on_pushButton_clicked();

private:
    Ui::deletwrt *ui;
};

#endif // DELETWRT_H
