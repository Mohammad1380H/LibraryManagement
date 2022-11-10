#include "addnew.h"
#include "ui_addnew.h"
#include "Users.hpp"
#include "QString"
#include "QPixmap"
#include "QByteArray"
#include "addaccount.h"
#include "QFileDialog"
#include "QMessageBox"
#include "editaccounts.h"
#include "get_giveback.h"
#include "manage_all_books.hpp"
addnew::addnew(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addnew)
{
    /////////////////////////show list with 3 parameter/////////
    ui->setupUi(this);
    QString id = ui->lineEdit->text();
    QString fname=ui->lineEdit_2->text();
    QString lname=ui->lineEdit_3->text();
    showList(id,fname,lname);
  }

addnew::~addnew()
{
    delete ui;
}


void addnew::on_tableView_clicked(const QModelIndex &index)
{
    Users obj;
    QString id = ui->lineEdit->text();
    QString fname=ui->lineEdit_2->text();
    QString lname=ui->lineEdit_3->text();
/////////////////////////three parameter (show)///////////////
    ui->label_7->setText(List1->record(index.row()).value(0).toString());
    ui->label_12->setText(List1->record(index.row()).value(1).toString());
    ui->label_8->setText(List1->record(index.row()).value(2).toString());
/////////////////////////////////show allgetsbooks//////////////
    obj.search_on_all_allocated_books(id,fname,lname).exec();
    ui->label_15->setText(List2->record(index.row()).value("allallocatedbooks").toString());
/////////////////////////////////show picture//////////////
    obj.search_on_pictures(id,fname,lname).exec();
    List3->record(index.row()).value( "picture" );
    QPixmap *outPixmap =  new QPixmap();
    outPixmap->load(List3->record(index.row()).value( "picture" ).toString());
    ui->label_2->setPixmap(*outPixmap);
///////////////////////////////close program//////////////////////////////
    QString Code_User= ui->label_7->text();
    manage_all_books obj_1;
    int the_number_of_User_Books= obj_1.number_of_User_Books(Code_User);
    ui->label_15->setText(QString::number(the_number_of_User_Books));
    obj_1.conclose();
    obj.conclose();
}


void addnew::on_lineEdit_textEdited(const QString &arg1)
{

    QString fname=ui->lineEdit_2->text();
    QString lname=ui->lineEdit_3->text();
    showList(arg1,fname,lname);
}


void addnew::on_lineEdit_2_textEdited(const QString &arg1)
{
    QString id=ui->lineEdit->text();
    QString lname=ui->lineEdit_3->text();
    showList(id,arg1,lname);
}


void addnew::on_lineEdit_3_textEdited(const QString &arg1)
{
    QString id=ui->lineEdit->text();
    QString fname=ui->lineEdit_2->text();
    showList(id,fname,arg1);
}


void addnew::on_pushButton_clicked()
{
    addaccount * addacc= new addaccount();
    addacc->show();
    this->close();
}


void addnew::on_pushButton_2_clicked()
{
Users obj;
QString Code= ui->label_7->text();
QString id = ui->lineEdit->text();
QString fname=ui->lineEdit_2->text();
QString lname=ui->lineEdit_3->text();
if(!obj.is_have_book(Code))
{
    obj.deleterec(Code).exec();
    showList(id,fname,lname);
    if(ui->checkBox->isChecked())
    QMessageBox::information(this,"پیغام حذف عضو","با موفقیت انجام شد!");
}
else
    QMessageBox::warning(this,"خطا","ابتدا کاربر باید کتابهای خود را برگرداند!!");
}




void addnew::showList(QString id, QString fname, QString lname)
{

    Users obj;


    obj.search_Idname(id,fname,lname).exec();
    List1->setQuery(obj.search_Idname(id,fname,lname));
    List2->setQuery(obj.search_on_all_allocated_books(id,fname,lname));
    List3->setQuery(obj.search_on_pictures(id,fname,lname));
    ui->tableView->setModel(List1);
    obj.conclose();
}

void addnew::on_pushButton_3_clicked()
{
    QString Code_User=ui->label_7->text();
    QString fname=ui->label_12->text();
    QString lname=ui->label_8->text();
    QString picaddress=List3->record(ui->tableView->currentIndex().row()).value( "picture" ).toString();
    if (Code_User!="")
    {
    editaccounts * form= new editaccounts(Code_User,fname,lname,picaddress);
    form->Code_for_edit=ui->label_7->text();
    form-> show();
    this->close();
    }
    else
        QMessageBox::warning(this,"خطا","لطفا یک کاربر را جهت ویرایش اطلاعات انتخاب کنید!!");
}





//note
//qDebug()<<"current index:"<<query2.at();
//     // Get the current line record
//QSqlRecord record = query2.record();
//     // Get the value recorded in the "id" and "name" field of two
//int id= record.value("id").toInt();
//QString name = record.value("name").toString();
////
