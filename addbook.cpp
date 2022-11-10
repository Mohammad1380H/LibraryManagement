#include "addbook.h"
#include "ui_addbook.h"
#include "Books.hpp"
#include "thabt_book.h"
#include "QMessageBox"
#include"editbooks.h"
#include "manage_all_books.hpp"
#include "pubwrttrs.h"
addbook::addbook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addbook)
{
    ui->setupUi(this);
    QString Code = ui->lineEdit->text();
    QString name_book = ui->lineEdit_2->text();
    showList(Code,name_book);
}

addbook::~addbook()
{
    delete ui;
}


void addbook::on_lineEdit_textEdited(const QString &arg1)
{
    QString name_book = ui->lineEdit_2->text();
    showList(arg1,name_book);
}


void addbook::on_lineEdit_2_textEdited(const QString &arg1)
{
    QString Code = ui->lineEdit->text();
    showList(Code,arg1);
}


void addbook::on_tableView_clicked(const QModelIndex &index)
{
    Books obj;

/////////////////////////three parameter (show)///////////////
    ui->label_7->setText(List1->record(index.row()).value(0).toString());
    ui->label_8->setText(List1->record(index.row()).value(1).toString());
/////////////////////////////////show allgetsbooks//////////////


    ui->label_12->setText(List2->record(index.row()).value(3).toString());
    ui->label_11->setText(List2->record(index.row()).value(4).toString());
    ui->label_15->setText(List2->record(index.row()).value(1).toString());
    ui->label_21->setText(List2->record(index.row()).value(2).toString());
    ui->label_19->setText(List2->record(index.row()).value(0).toString());
    QString Code_Book_label= ui->label_7->text();
    manage_all_books obj_1;
    int number_of_Book_Users = obj_1.number_of_Book_Users(Code_Book_label);
    ui->label_20->setText(QString::number(number_of_Book_Users));

    obj_1.conclose();

///////////////////////////////close program//////////////////////////////
    obj.conclose();
}

void addbook::showList(QString Code_book, QString name_book)
{
    qDebug() << Code_book << "000" << name_book << endl;
    Books obj;
    obj.search_Code_name_books(Code_book,name_book).exec();
    obj.search_Other_info_book(Code_book,name_book).exec();
    List1->setQuery(obj.search_Code_name_books(Code_book,name_book));
    List2->setQuery(obj.search_Other_info_book(Code_book,name_book));
    ui->tableView->setModel(List1);


    obj.conclose();
}

void addbook::on_pushButton_clicked()
{
   thabt_book * Form= new thabt_book();
   Form->show();
   this->close();
}


void addbook::on_pushButton_2_clicked()
{
    Books obj;
    QString Code_Book= ui->label_7->text();
    QString name_Book=ui->lineEdit_2->text();
    QString Code_Book_to_Search= ui->lineEdit->text();
    if(!obj.is_Borrowed(Code_Book))
    {
    obj.deletbook(Code_Book).exec();//
    showList(Code_Book_to_Search,name_Book);
    if(ui->checkBox->isChecked())
    QMessageBox::information(this,"پیغام حذف کتاب","با موفقیت انجام شد!");
    }
    else
    QMessageBox::warning(this,"خطا","این کتاب نزد کسی به امانت است!!!");
}


void addbook::on_pushButton_3_clicked()
{
    QString Code_Book= ui->label_7->text();
    QString name_Book= ui->label_8->text();
    QString wrt= ui->label_12->text();
    QString trs= ui->label_15->text();
    QString pub= ui->label_19->text();
    if (Code_Book!="")
    {

        editbooks * form = new editbooks(Code_Book,name_Book,pub,wrt,trs);

        form->show();
        this->close();
    }
    else
        QMessageBox::warning(this,"خطا","لطفا یک کتاب را جهت ویرایش اطلاعات انتخاب کنید!!");

}



void addbook::on_pushButton_4_clicked()
{
    pubwrttrs * form= new pubwrttrs();
    form->show();
    this->close();
}

