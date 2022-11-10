#include "Books.hpp"

Books::Books()
{

}
QSqlQuery Books::search_Code_name_books(QString Code_book, QString name_book)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("SELECT Book_Id , Bookname FROM Books where Book_Id like '%"+Code_book+"%' and Bookname like '%"+name_book+"%' ");
    myqry->exec();
    return *myqry;
}
QSqlQuery Books::search_Other_info_book(QString Code_book, QString name_book)
{
    QString pre=
            "SELECT [main].[Publishers].[publishers],"
                   "[main].[Trans].[fname], "
                   "[main].[Trans].[lname],"
                   "[main].[Wrt].[fname] AS [fname1], "
                   "[main].[Wrt].[lname] AS [lname1]"
            "FROM   [main].[Books]"
                   "LEFT OUTER JOIN [main].[Publishers] ON [main].[Publishers].[pubcode] = [main].[Books].[pub_Id]"
                   "LEFT OUTER JOIN [main].[Trans] ON [main].[Trans].[Translater_Id] = [main].[Books].[translater_Id]"
                   "LEFT OUTER JOIN [main].[Wrt] ON [main].[Wrt].[Writer_Id] = [main].[Books].[writer_Id]"


            "where Book_Id like '%"+Code_book+"%' and Bookname like '%"+name_book+"%';";

    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare(pre);
    myqry->exec();
    return *myqry;
}


QSqlQuery Books::show_pub( QString pub)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("SELECT publishers  from Publishers where publishers like '%"+pub+"%' ");
    myqry->exec();
    return *myqry;
}
QSqlQuery Books::show_wrt(QString name_Id)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("SELECT Writer_Id, fname , lname  from Wrt where fname like '%"+name_Id+"%' OR lname like '%"+name_Id+"%'");
    return *myqry;
}
QSqlQuery Books::show_trs(QString name_Id)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("SELECT  Translater_Id,fname , lname  from Trans where fname like '%"+name_Id+"%' OR lname like '%"+name_Id+"%'");
    return *myqry;
}
QSqlQuery Books::save_info(QString Code_Book, QString name_book, QString pub, QString wrt, QString trs)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("insert into Books (Book_Id,Bookname,writer_Id,translater_Id,pub_Id) VALUES ('"+Code_Book+"','"+name_book+"','"+wrt+"','"+trs+"',(select pubcode from Publishers where publishers='"+pub+"'))");
    return *myqry;
}

bool Books::is_repated(QString Code_book)
{

    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("select Book_Id from Books where Book_Id='"+Code_book+"' ");
    myqry->exec();
    while (myqry->next())
    {
    QString code = myqry->value(0).toString();
    if (code==Code_book)
        return true;

    }
        return false;

}
bool Books::is_number(QString Code_Book)
{
    for (auto temp: Code_Book)
    {
        if (!(temp>=48&&temp<=57))
            return false;

    }
    return true;
}

QSqlQuery Books::deletbook(QString Code_Book)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("Delete from Books where Book_Id='"+Code_Book+"'");
    return *myqry;
}

QSqlQuery Books::edit_info(QString Old_Code_Book,QString Code_Book, QString name_book, QString pub, QString wrt, QString trs)
{
    con_open();

    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("update Books set Book_Id='"+Code_Book+"',Bookname='"+name_book+"',writer_Id='"+wrt+"',translater_Id='"+trs+"',pub_Id=(select pubcode from Publishers where publishers='"+pub+"') where Book_Id = '"+Old_Code_Book+"'");
    return *myqry;
}
//INSERT INTO bar (description, foo_id) VALUES counter
//    ( 'testing',     (SELECT id from foo WHERE type='blue') ),
//    ( 'another row', (SELECT id from foo WHERE type='red' ) );
//    myqry->prepare("insert into Books (Book_Id,Bookname,writer_Id,translater_Id,counter,pub_Id) VALUES ('"+Code_Book+"','"+name_book+"',(select Writer_Id from Wrt where fname='"+wrt+"'),(select Translater_Id from Trans where fname='"+trs+"'),'0',
//(select pubcode from Publishers where publishers='"+pub+"'))");
bool Books::is_Borrowed(QString Code_book)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    qDebug() << Code_book << "gereftar" << endl;
    myqry->prepare("select Dategiveback from GetGive where BookId='"+Code_book+"'  ");
    myqry->exec();
    if(myqry->last())
    {
    QString Dategiveback_string = myqry->value(0).toString();
    if (Dategiveback_string=="")
        return true;

    else
        return false;
    }
    else
        return false;
}
