#include "editaccounts.h"
#include "ui_editaccounts.h"
#include "QFileDialog"
#include "Users.hpp"
#include"QDir"
#include "addnew.h"
#include "QCloseEvent"
QString edit_addresspic;
editaccounts::editaccounts(QString Code_User,QString fname,QString lname,QString picaddress,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editaccounts)
{
    ui->setupUi(this);
    ui->lineEdit_4->setText(Code_User);
    ui->lineEdit_5->setText(fname);
    ui->lineEdit_6->setText(lname);
    edit_addresspic=picaddress;
}

editaccounts::~editaccounts()
{
    delete ui;
}
void editaccounts::closeEvent(QCloseEvent *event)
{
    addnew * form= new addnew();
    form->show();
    event->accept();

}
void editaccounts::on_pushButton_4_clicked()
{
    this->close();
}


void editaccounts::on_pushButton_3_clicked()
{
        QString filter= "Picturs(*.jpg *.png *jpeg *.gif *.jfif)";
        edit_addresspic= QFileDialog::getOpenFileName(this,"ویرایش عکس",QDir::homePath(),filter);
}


void editaccounts::on_pushButton_clicked()
{
    Users obj;
    QString Code= ui->lineEdit_4->text();
    QString fname = ui->lineEdit_5->text();
    QString lname = ui->lineEdit_6->text();
    if (Code=="")//not null
    {
        QMessageBox::warning(this,"خطا" ,"کد اشتراک الزامی است!!" );
        return;
    }
    if (obj.is_repated(Code)&&(Code!=Code_for_edit))// not dop Except its old code that he not to change it
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
    if (!obj.edit_informations(Code_for_edit,Code,fname,lname,edit_addresspic).exec())//error database or seccess !
    {
        QMessageBox::warning(this,"خطا" , obj.saveinformations(Code,fname,lname,edit_addresspic).lastError().text());
        return;
    }
    QMessageBox::information(this,"پیغام ثبت" ,"با موفقیت انجام شد!!" );
    obj.conclose();
}

