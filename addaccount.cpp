#include "addaccount.h"
#include "ui_addaccount.h"
#include "QFileDialog"
#include "Users.hpp"
#include"QDir"
#include "addnew.h"
#include "QCloseEvent"

QString addresspic;

addaccount::addaccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addaccount)
{
    ui->setupUi(this);


}

void addaccount::closeEvent(QCloseEvent *event)
{
    addnew * form= new addnew();
    form->show();
    event->accept();

}
addaccount::~addaccount()
{

    delete ui;
}

void addaccount::on_pushButton_2_clicked()
{
    QString filter= "Picturs(*.jpg *.png *jpeg *.gif *.jfif)";
    addresspic= QFileDialog::getOpenFileName(this,"انتخاب عکس",QDir::homePath(),filter);
}

void addaccount::on_pushButton_clicked()
{
    Users obj;
    QString Code= ui->lineEdit->text();

    QString fname = ui->lineEdit_2->text();
    QString lname = ui->lineEdit_3->text();

    if (Code=="")//not null
    {
        QMessageBox::warning(this,"خطا" ,"کد اشتراک الزامی است!!" );
        return;
    }
    if (obj.is_repated(Code))// not dop
    {
        QMessageBox::warning(this,"خطا" ,"کد اشتراک تکراری است!!" );
        return;
    }
    if (!obj.is_number(Code))// is char
    {
        QMessageBox::warning(this,"خطا" , "کد اشتراک بایستی شامل عدد باشد!!");
        return;
    }
    if (!obj.check_len(Code,10))// exact 10 digits
    {
        QMessageBox::warning(this,"خطا" , "کد اشتراک بایستی ده رقمی باشد!!");
        return;
    }

    if (!obj.saveinformations(Code,fname,lname,addresspic).exec())//error database or seccess !
    {
        QMessageBox::warning(this,"خطا" , obj.saveinformations(Code,fname,lname,addresspic).lastError().text());
        return;
    }
    QMessageBox::information(this,"پیغام ثبت" ,"با موفقیت انجام شد!!" );
    obj.conclose();

}





void addaccount::on_pushButton_4_clicked()
{
    this->close();
}

