#include "wtp.hpp"

wtp::wtp()
{

}
QSqlQuery wtp::addwrt(QString fname, QString lname, QString bithday, bool gender)
{

    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    if(gender==true)
        myqry->prepare("insert into Wrt (fname,lname,birthday,gender) VALUES ('"+fname+"','"+lname+"','"+bithday+"','true') ");
    else
    {
        myqry->prepare("insert into Wrt (fname,lname,birthday,gender) VALUES ('"+fname+"','"+lname+"','"+bithday+"','false') ");
    }
    myqry->exec();

    return *myqry;
}


QSqlQuery wtp::addtrs(QString fname, QString lname, QString bithday, bool gender)
{

    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    if(gender==true)
        myqry->prepare("insert into Trans (fname,lname,birthday,gender) VALUES ('"+fname+"','"+lname+"','"+bithday+"','true') ");
    else
    {
        myqry->prepare("insert into Trans (fname,lname,birthday,gender) VALUES ('"+fname+"','"+lname+"','"+bithday+"','false') ");
    }
    myqry->exec();

    return *myqry;
}
QSqlQuery wtp::addpub(QString name)
{

    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);

    myqry->prepare("insert into Publishers (publishers) VALUES ('"+name+"') ");
    myqry->exec();

    return *myqry;
}



