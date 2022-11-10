#ifndef PUBWRTTRS_H
#define PUBWRTTRS_H

#include <QWidget>

namespace Ui {
class pubwrttrs;
}

class pubwrttrs : public QWidget
{
    Q_OBJECT

public:
    explicit pubwrttrs(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent *event);
    ~pubwrttrs();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();



private:
    Ui::pubwrttrs *ui;
};

#endif // PUBWRTTRS_H
