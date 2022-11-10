#include "get_giveback.h"
#include "ui_get_giveback.h"
#include "QMessageBox"
#include "manage_all_books.hpp"
#include "addnew.h"
#include "addbook.h"
#include "queries.h"
get_giveback::get_giveback(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::get_giveback)
{
    ui->setupUi(this);
    showList("","");
    ui->spinBox->setRange(0,10);// add number in setting
    ui->pushButton_8->setHidden(true);
}

get_giveback::~get_giveback()
{
    delete ui;
}

//////////////
/// \brief get_giveback::on_pushButton_clicked
/// baray amanat
void get_giveback::on_pushButton_clicked()
{
    QString Code_User_label= ui->label_35->text();
    int number=ui->spinBox->value();
    QString Code_Book=ui->label_7->text();
    manage_all_books obj;
    if (Code_User_label=="")
    {
        QMessageBox::warning(this,"خطا", "لطفا یک کاربر را جهت امانت انتخاب کنید!!");
        return;
    }
    if (Code_Book=="")
    {
        QMessageBox::warning(this,"خطا", "لطفا یک کتاب را جهت امانت انتخاب کنید!!");
        return;
    }

    if (obj.is_repated(Code_Book))
    {
        QMessageBox::critical(this,"خطا","این کتاب قبلا به امانت برده شده است!!!");
        return;
    }
    if (!obj.is_allowed_to_borrowed(Code_User_label,number))
    {
        QMessageBox::critical(this,"خطا","این کاربر نمی تواند بیش از حد تعیین شده کتاب به امانت ببرد!!!");
        return;
    }
    if (!obj.Borrowing(Code_Book,Code_User_label).exec())
    {
        QMessageBox::warning(this,"خطا" , obj.Borrowing(Code_Book,Code_User_label).lastError().text());
        return;
    }
    QMessageBox::information(this,"ثبت امانت","کتاب با موفقیت به امانت داده شد!!");
    on_pushButton_5_clicked();
    on_pushButton_6_clicked();
    obj.conclose();
}





////////////////
/// \brief get_giveback::showList
/// \param Code_book
/// \param name_book
/// baraye search
void get_giveback::showList(QString Code_book, QString name_book)
{
    Books obj;
    obj.search_Code_name_books(Code_book,name_book).exec();
    obj.search_Other_info_book(Code_book,name_book).exec();
    List1->setQuery(obj.search_Code_name_books(Code_book,name_book));
    List2->setQuery(obj.search_Other_info_book(Code_book,name_book));
    obj.conclose();

}
//////////////////
/// \brief get_giveback::show_status
/// \param index
///baray didan mohlat ketab
void get_giveback::show_status(const QModelIndex &index)
{
    manage_all_books obj;
    obj.con_open();
    QString Code_Book=List3->record(index.row()).value(0).toString();
    QString remind_deadline=obj.Deadline_left(Code_Book);
    ui->label_24->setText(remind_deadline);
    QString remind_deadline_label=ui->label_24->text();
    if ((remind_deadline=="-")&&(remind_deadline_label!=""))
    {
        ui->label_25->setText("<html><head/><body><p align=\"center\"><span style=\" color:#000000;\">!قابل امانت</span></p></body></html>");
    }

    else if ((remind_deadline.toInt()<0)&&(remind_deadline_label!=""))
    {

        ui->label_25->setText("<html><head/><body><p align=\"center\"><span style=\" color:#f90000;\">!تاخیر در برگشت کتاب</span></p></body></html>");

    }
    else if((remind_deadline.toInt()==0)&&(remind_deadline_label!=""))
    {
        ui->label_25->setText("<html><head/><body><p align=\"center\"><span style=\" color:#000000;\">!کتاب را تحویل دهید</span></p></body></html>");

    }
    else if(remind_deadline_label!="")
    {
        ui->label_25->setText("<html><head/><body><p align=\"center\"><span style=\" color:##000000;\">!روز مهلت باقی است</span></p></body></html>");

    }

    obj.conclose();
}

/////////////////////
/// \brief get_giveback::on_pushButton_2_clicked
///baraye bargasht
void get_giveback::on_pushButton_2_clicked(bool tamdid)
{

    QString Code_Book=List3->record(ui->tableView_2->currentIndex().row()).value(0).toString();
    QString Code_User_label= ui->label_35->text();
    if (Code_Book=="")
    {
        QMessageBox::warning(this,"خطا", "لطفا یک کتاب را جهت برگشت انتخاب کنید!!");
        return;
    }
    manage_all_books obj;
    if (!obj.is_repated(Code_Book))
    {
        QMessageBox::critical(this,"خطا","این کتاب به امانت برده نشده است!!!");
        return ;
    }
    if (!obj.is_his_book(Code_Book,Code_User_label))
    {
        QMessageBox::critical(this,"خطا","کاربر مورد نظر،این کتاب را به امانت نبرده است!!!");
        return;
    }
    if (!obj.return_book(Code_Book,Code_User_label).exec())
    {
        QMessageBox::warning(this,"خطا" , obj.return_book(Code_Book,Code_User_label).lastError().text());
        return;
    }
    QMessageBox::information(this,"برگشت کتاب","کتاب با موفقیت برگشت داده شد!!");
    on_pushButton_5_clicked(tamdid);
    on_pushButton_6_clicked();
    obj.conclose();

}

//////////////////////////////////////
/// \brief get_giveback::on_pushButton_5_clicked
/// entekhab karbar baray amant dadan
///
void get_giveback::on_pushButton_5_clicked(bool tamdid)
{
    manage_all_books obj_1;
    Users obj;
    QString Code_user= ui->lineEdit_3->text();
    QSqlQuery myquery=  obj.search_Idname(Code_user,"","");
    myquery.first();
    QString Code_string=myquery.value(0).toString();
    QString fname_string= myquery.value(1).toString();
    QString lname_string= myquery.value(2).toString();
    ui->label_35->setText(Code_string);
    ui->label_31->setText(fname_string);
    ui->label_34->setText(lname_string);
    List3->setQuery(obj_1.List_of_User_books(Code_string));
    ui->tableView_2->setModel(List3);
    int number=obj_1.number_of_book_now(Code_string);

if (number>default_number&&tamdid!=true)
{
    ui->spinBox->setValue( obj_1.number_of_book_now(Code_string));
}
else if (tamdid!=true)
{
    ui->spinBox->setValue( default_number);
}
    obj.conclose();
}


/////////////////////////
/// \brief get_giveback::on_tableView_2_clicked
/// \param index
///list jotob amanati
void get_giveback::on_tableView_2_clicked(const QModelIndex &index)
{
show_status(index);
}

/////////////////////////////
/// \brief get_giveback::on_pushButton_6_clicked
///entekhab ketab baraye amanat
void get_giveback::on_pushButton_6_clicked()
{
    ui->label_37->clear();
    QString Code_Book=ui->lineEdit->text();
    QString name_Book= ui->lineEdit_2->text();
    showList(Code_Book,name_Book);
    ui->label_24->clear();
    ui->label_7->setText(List1->record(0).value(0).toString());
    ui->label_8->setText(List1->record(0).value(1).toString());
/////////////////////////////////show allgetsbooks////////////////
    ui->label_12->setText(List2->record(0).value(3).toString());
    ui->label_11->setText(List2->record(0).value(4).toString());
    ui->label_15->setText(List2->record(0).value(1).toString());
    ui->label_22->setText(List2->record(0).value(2).toString());
    ui->label_20->setText(List2->record(0).value(0).toString());
    manage_all_books obj;
    QString Code_book_label= ui->label_7->text();
    if ((obj.is_repated(Code_book_label))&&(Code_book_label!=""))
    {
        ui->label_37->setText("<html><head/><body><p align=\"center\"><span style=\" color:#f90000;\">!غیر قابل امانت</span></p></body></html>");
        ui->pushButton_8->setHidden(false);
    }
    else if (Code_book_label!="")
    {
        ui->label_37->setText("<html><head/><body><p align=\"center\"><span style=\" color:#000000;\">!قابل امانت</span></p></body></html>");
        ui->pushButton_8->setHidden(true);
    }

}


void get_giveback::on_pushButton_4_clicked()
{
    addnew * form= new  addnew();
    form->show();
}


void get_giveback::on_pushButton_7_clicked()
{
    addbook * form= new addbook();
    form->show();
}


void get_giveback::on_pushButton_8_clicked()
{
    QString Code_Book= ui->label_7->text();
    queries * form = new queries(Code_Book);
    form->show();
}


void get_giveback::on_pushButton_3_clicked()
{
    QString Code_Book= List3->record(ui->tableView_2->currentIndex().row()).value(0).toString();
    on_pushButton_2_clicked(true);//bargasht
    ui->lineEdit->setText(Code_Book);//
    on_pushButton_6_clicked();//update book
    on_pushButton_clicked();//amanat
}

