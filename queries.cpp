#include "queries.h"
#include "ui_queries.h"
#include "manage_all_books.hpp"
#include"QMessageBox"
queries::queries(QString recCode,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::queries)
{

    ui->setupUi(this);
    Code_book_for_query=recCode;
    ui->lineEdit->setText(Code_book_for_query);
    manage_all_books obj;

    List1->setQuery(obj.Delayed_Users());
    ui->tableView->setModel(List1);
    ui->label_19->setText(QString::number(100.0-obj.percent()));
    obj.conclose();
}

queries::~queries()
{
    delete ui;
}




void queries::on_pushButton_2_clicked()
{
        manage_all_books obj;
        List2->setQuery(obj.best_User());
        ui->tableView_2->setModel(List2);
        //QMessageBox::information(this,"fd",obj.best_User().lastError().text());
        obj.conclose();
}


void queries::on_pushButton_clicked()
{
    manage_all_books obj;
    QString Code_Book= ui->lineEdit->text();
    ui->label_9->setText(obj.User_book(Code_Book).value(0).toString());
    ui->label_10->setText(obj.User_book(Code_Book).value(1).toString());
    ui->label_12->setText(obj.User_book(Code_Book).value(2).toString());
    ui->label_14->setText(obj.User_book(Code_Book).value(3).toString());
}


void queries::on_pushButton_3_clicked()
{
    manage_all_books obj;
    List3->setQuery(obj.best_Book());
    ui->tableView_3->setModel(List3);
    //QMessageBox::information(this,"fd",obj.best_User().lastError().text());
    obj.conclose();
}

