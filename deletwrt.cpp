#include "deletwrt.h"
#include "ui_deletwrt.h"
#include "wtp.hpp"
#include "QMessageBox"
deletwrt::deletwrt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deletwrt)
{
    ui->setupUi(this);
}

deletwrt::~deletwrt()
{
    delete ui;
}

void deletwrt::on_pushButton_clicked()
{
    QString Code_wrt= ui->lineEdit->text();
    wtp obj;

    if (obj.deletwrt(Code_wrt).lastError().text()!="")
    {

        QMessageBox::warning(this,"خطا",obj.deletwrt(Code_wrt).lastError().text());
    }
}

