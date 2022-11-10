#include "thabt_book.h"
#include "ui_thabt_book.h"
#include "Books.hpp"
#include "QMessageBox"
#include "addbook.h"
#include "QCloseEvent"
thabt_book::thabt_book(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::thabt_book)
{
    Books obj;
    ui->setupUi(this);
    showList_pub("");
    showList_wrt("");
    showList_trs("");
}

thabt_book::~thabt_book()
{

    delete ui;
}

void thabt_book::on_pushButton_4_clicked()
{

    this->close();
}

void thabt_book::closeEvent(QCloseEvent *event)
{
    addbook * form= new addbook();
    form->show();
    event->accept();

}
void thabt_book::on_lineEdit_11_textEdited(const QString &arg1)
{
    showList_pub(arg1 );

}

void thabt_book::on_lineEdit_10_textEdited(const QString &arg1)
{
    showList_wrt(arg1);
}
void thabt_book::on_lineEdit_8_textEdited(const QString &arg1)
{
    showList_trs(arg1);
}

void thabt_book::on_pushButton_clicked()
{
    QString Code_Book= ui->lineEdit_4->text();
    QString name_book= ui->lineEdit_5->text();
    QString pub= ui->comboBox->currentText();
    QString wrt= ui->comboBox_2->currentText();
    QString trs= ui->comboBox_3->currentText();
    Books obj;
    if (Code_Book=="")//not null
    {
        QMessageBox::warning(this,"خطا" ,"کد کتاب الزامی است!!" );
        return;
    }
    if (obj.is_repated(Code_Book))// not dop
    {
        QMessageBox::warning(this,"خطا" ,"کد کتاب تکراری است!!" );
        return;
    }
    if (!obj.is_number(Code_Book))// is char
    {
        QMessageBox::warning(this,"خطا" , "کد اشتراک بایستی شامل عدد باشد!!");
        return;
    }
    if (obj.save_info(Code_Book,name_book,pub,Separation(wrt),Separation(trs)).exec())
    {
        QMessageBox::information(this,"ثبت کتاب","با موفقیت انجام شد !!");
    }
obj.conclose();
}

////////////////////////
/// \brief thabt_book::showList_pub
/// \param pub
///
void thabt_book::showList_pub(QString pub)
{
    Books obj;
    List1->setQuery(obj.show_pub(pub));

    ui->comboBox->setModel(List1);
    obj.conclose();
}
void thabt_book::showList_wrt(QString wrt)
{
    ui->comboBox_2->clear();
    Books obj;
    QSqlQuery qry= obj.show_wrt(wrt);
    qry.exec();
    while (qry.next())
    {
    QString Item = qry.value(0).toString()+"-"+qry.value(1).toString()+" "+qry.value(2).toString();
    ui->comboBox_2->addItem(Item);
    }
    obj.conclose();
}

void thabt_book::showList_trs(QString trs)
{
    ui->comboBox_3->clear();
    Books obj;
    QSqlQuery qry= obj.show_trs(trs);
    qry.exec();
    while (qry.next())
    {
    QString Item = qry.value(0).toString()+"-"+qry.value(1).toString()+" "+qry.value(2).toString();
    ui->comboBox_3->addItem(Item);
    }
    obj.conclose();
}



QString thabt_book::Separation(QString name)
{
    QString new_name="";
    for (auto temp : name)
    {
        if (temp!='-')
            new_name+=temp;
        else
            return new_name;

    }
    return new_name;
}
