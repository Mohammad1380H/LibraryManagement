#include "Users.hpp"
#include "QFileDialog"
#include <QCursor>
Users::Users()
{

}

QSqlQuery Users::search_Idname(QString id, QString fname, QString lname)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("SELECT Code , fname, lname FROM Users where Code like '%"+id+"%' and fname like '%"+fname+"%' and lname like '%"+lname+"%'  ");
    myqry->exec();
    return *myqry;
}
QSqlQuery Users::search_on_pictures(QString id, QString fname, QString lname)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("SELECT picture FROM Users where Code like '%"+id+"%' and fname like '%"+fname+"%' and lname like '%"+lname+"%'  ");
    myqry->exec();
    return *myqry;
}
QSqlQuery Users::search_on_all_allocated_books(QString id, QString fname, QString lname)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("SELECT allallocatedbooks FROM Users where Code like '%"+id+"%' and fname like '%"+fname+"%' and lname like '%"+lname+"%'  ");
    myqry->exec();
    return *myqry;
}
QSqlQuery Users::saveinformations(QString code,QString fname,QString lname,QString picaddress)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("insert into Users (Code,fname,lname,picture) VALUES ('"+code+"','"+fname+"','"+lname+"','"+picaddress+"')");
    return *myqry;
}

bool Users::is_repated(QString Code)
{

    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("select Code from Users where Code='"+Code+"' ");
    myqry->exec();
    while (myqry->next())
    {

    QString code = myqry->value(0).toString();
    if (code==Code)
        return true;

    }
        return false;

}
bool Users::check_len(QString Code,int dec)
{
if (Code.length()==dec)
    return true;
else
    return false;
}

bool Users::is_number(QString Code)
{
    for (auto temp: Code)
    {
        if (!(temp>=48&&temp<=57))
            return false;

    }
    return true;
}

QSqlQuery Users::deleterec(QString Code)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("Delete from Users where Code='"+Code+"'");

    return *myqry;
}
QSqlQuery Users::edit_informations(QString old_Code,QString code,QString fname,QString lname,QString picaddress)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("update Users set Code='"+code+"',fname='"+fname+"',lname='"+lname+"',picture='"+picaddress+"' where Code='"+old_Code+"'");
    return *myqry;
}

bool Users::is_have_book(QString Code_User)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("select Dategiveback from GetGive where UserId='"+Code_User+"' ");
    myqry->exec();

    while (myqry->next())
    {
    QString Dategiveback_string= myqry->value(0).toString();
    if (Dategiveback_string=="")
        return true;

    }
    return false;

}
