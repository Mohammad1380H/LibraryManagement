#include "pubwrttrs.h"
#include "ui_pubwrttrs.h"
#include "wtp.hpp"
#include "QMessageBox"
#include "deletwrt.h"
#include "addbook.h"
#include "QCloseEvent"
pubwrttrs::pubwrttrs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pubwrttrs)
{
    ui->setupUi(this);
}

pubwrttrs::~pubwrttrs()
{
    delete ui;
}
void pubwrttrs::closeEvent(QCloseEvent *event)
{
    addbook * form= new addbook();
    form->show();
    event->accept();

}
void pubwrttrs::on_pushButton_clicked()
{
    QString fname= ui->lineEdit->text();
    QString lname = ui->lineEdit_2->text();
    QString birthday = ui->lineEdit_3->text();
    if (fname=="" || lname=="")
    {
        QMessageBox::warning(this,"خطا","لطفاً نام و نام خانوادگی را وارد کنید!");
        return;
    }
    bool flag=true;
    if (ui->radioButton->isChecked())
    {
        flag=true;
    }
    else if (ui->radioButton_2->isChecked())
    {
        flag= false;
    }
        wtp obj;
    obj.addwrt(fname,lname,birthday,flag);

    QMessageBox::information(this,"اعلام","انجام شد!") ;
    obj.conclose();

}


void pubwrttrs::on_pushButton_6_clicked()
{
    QString fname= ui->lineEdit_5->text();
    QString lname = ui->lineEdit_6->text();
    QString birthday = ui->lineEdit_7->text();
    if (fname=="" || lname=="")
    {
        QMessageBox::warning(this,"خطا","لطفاً نام و نام خانوادگی را وارد کنید!");
        return;
    }
    bool flag=true;
    if (ui->radioButton_3->isChecked())
    {
        flag=true;
    }
    else if (ui->radioButton_4->isChecked())
    {
        flag= false;
    }

    wtp obj;
    obj.addtrs(fname,lname,birthday,flag);
    QMessageBox::information(this,"اعلام","انجام شد!!") ;
    obj.conclose();
}


void pubwrttrs::on_pushButton_3_clicked()
{
    QString name= ui->lineEdit_4->text();

    if (name=="")
    {
        QMessageBox::warning(this,"خطا","لطفاً نام را وارد کنید!");
        return;
    }

    wtp obj;
    obj.addpub(name);

    QMessageBox::information(this,"اعلام","انجام شد !!") ;
    obj.conclose();
}



