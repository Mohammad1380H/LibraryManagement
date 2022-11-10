#include "manage_all_books.hpp"
#include "QDate"
#include "QSqlRecord"
manage_all_books::manage_all_books()
{

}

QSqlQuery manage_all_books::Borrowing(QString Code_Book, QString Code_User)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("insert into GetGive (BookId,Dateget,UserId) VALUES ('"+Code_Book+"',Date('now','localtime'),'"+Code_User+"')");
    return *myqry;
}
///////////////////////////////////////
/// \brief manage_all_books::Deadline_left
/// \param Code_Book
/// \return
///
QString manage_all_books::Deadline_left(QString Code_Book)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("SELECT Dateget ,Dategiveback FROM GetGive where BookId like '%"+Code_Book+"%'");
    myqry->exec();
    myqry->last();
    if( myqry->value(1)=="")
    {
    QDate second= QDate::fromString( myqry->value(0).toString(),"yyyy-MM-dd" );
    second=second.addDays(14);
    QDate first= QDate::currentDate();
    int dif= first.daysTo(second);
    QString dif_string= QString::number(dif);
    return dif_string;
    }
    else
    {
        qDebug() << myqry->value(0).toString() << "here is " << endl;
        return "-" ;
    }
}////// ta inja
bool manage_all_books::is_repated(QString Code_Book)
{

    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("select Dategiveback from GetGive where BookId='"+Code_Book+"' ");
    myqry->exec();

    if(myqry->last())
    {
    QString Dategiveback_string=myqry->value(0).toString();
    if (Dategiveback_string==NULL)
        return true;
    else
        return false;
    }
    else
    {
        return false;
    }

}
QSqlQuery manage_all_books::return_book( QString Code_Book,QString Code_User)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare(" update GetGive set Dategiveback=DATE('now','localtime') where BookId='"+Code_Book+"' and UserId='"+Code_User+"' and Dategiveback IS NULL  ");
    return *myqry;
}
bool manage_all_books::is_his_book(QString Code_Book, QString Code_User)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("select Dategiveback from GetGive where BookId='"+Code_Book+"' and UserId='"+Code_User+"' ");
    myqry->exec();
    if(myqry->last())
    {
    QString Dategiveback_string=myqry->value(0).toString();
    if (Dategiveback_string==NULL)
        return true;
    else
        return false;
    }
    else
    {
        return false;
    }

}
int manage_all_books::number_of_User_Books(QString Code_User)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("SELECT COUNT(*) from GetGive where  UserId='"+Code_User+"'  ");
    myqry->exec();
    myqry->first();
    int x = myqry->value(0).toInt();
    return x;
}

int manage_all_books::number_of_Book_Users(QString Code_Book)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("SELECT COUNT(*) from GetGive where  BookId='"+Code_Book+"'  ");
    myqry->exec();
    myqry->first();
    int x = myqry->value(0).toInt();
    return x;
}
bool manage_all_books::is_allowed_to_borrowed(QString Code_User, int number)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("select Dategiveback from GetGive where UserId='"+Code_User+"' ");
    myqry->exec();
    int is_Borr=0;
    while (myqry->next())
    {
    QString flag = myqry->value(0).toString();
    if (flag==NULL)
        is_Borr++;

    }

    if(is_Borr<number)
        return true;
    else
       return false;
}



QSqlQuery manage_all_books::List_of_User_books(QString Code_User)
{
    con_open();

    QSqlQuery * myqry= new QSqlQuery(msAccess);

    myqry->prepare(
                "SELECT [main].[GetGive].[BookId], "
                       "[main].[Books].[Bookname]"
                "FROM   [main].[Books]"
                       "LEFT OUTER JOIN [main].[GetGive] ON [main].[Books].[Book_Id] = [main].[GetGive].[BookId]"

                    "where UserId='"+Code_User+"' and Dategiveback IS NULL");
  myqry->exec();
  return *myqry;

}


int manage_all_books::number_of_book_now(QString Code_User)
{

    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare(" select COUNT(*) from GetGive where UserId='"+Code_User+"' and Dategiveback IS NULL ");
    myqry->exec();
    myqry->first();
    int number= myqry->value(0).toInt();
    return number;
}
///////////////////////////////////////////////////
//////////////show queries//////////////////////
///


QSqlQuery manage_all_books::Delayed_Users()
{
    QDate today = QDate::currentDate();
    QString today_string=today.toString("yyyy-MM-dd");


    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("SELECT [main].[Users].[fname],"
                   "[main].[Users].[lname],"
                   "[main].[Books].[Bookname]"
            "FROM   [main].[Books]"
                   "INNER JOIN [main].[GetGive] ON [main].[Books].[Book_Id] = [main].[GetGive].[BookId]"
                   "INNER JOIN [main].[Users] ON [main].[Users].[Code] = [main].[GetGive].[UserId]"
        "where JULIANDAY('now','localtime') - JULIANDAY(Dateget) > 15 and Dategiveback IS NULL");

    myqry->exec();
    return *myqry;

}
//dar soorat kharabi kar ... hamin ra copy con
//SELECT [main].[Users].[fname] ,"
//       "[main].[Users].[lname],"
//       "[main].[Books].[Bookname]"
//"FROM   [main].[Books]"
//       "LEFT OUTER JOIN [main].[GetGive] ON [main].[Books].[Book_Id] = [main].[GetGive].[BookId]"
//       "LEFT OUTER JOIN [main].[Publishers] ON [main].[Publishers].[pubcode] = [main].[Books].[pub_Id]"
//       "LEFT OUTER JOIN [main].[Trans] ON [main].[Trans].[Translater_Id] = [main].[Books].[translater_Id]"
//       "LEFT OUTER JOIN [main].[Users] ON [main].[Users].[Code] = [main].[GetGive].[UserId]"
//       "LEFT OUTER JOIN [main].[Wrt] ON [main].[Wrt].[Writer_Id] = [main].[Books].[writer_Id]"
QSqlQuery manage_all_books::User_book(QString Code_Book)
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare(" SELECT [main].[Users].[fname],"
       "[main].[Users].[lname], "
       "[main].[Users].[Code],"
       "[main].[Books].[Bookname]"
"FROM   [main].[Books]"
       "LEFT OUTER JOIN [main].[GetGive] ON [main].[Books].[Book_Id] = [main].[GetGive].[BookId]"
       "LEFT OUTER JOIN [main].[Publishers] ON [main].[Publishers].[pubcode] = [main].[Books].[pub_Id]"
       "LEFT OUTER JOIN [main].[Trans] ON [main].[Trans].[Translater_Id] = [main].[Books].[translater_Id]"
       "LEFT OUTER JOIN [main].[Users] ON [main].[Users].[Code] = [main].[GetGive].[UserId]"
       "LEFT OUTER JOIN [main].[Wrt] ON [main].[Wrt].[Writer_Id] = [main].[Books].[writer_Id]"
"where BookId ='"+Code_Book+"' and Dategiveback IS NULL;");
    myqry->exec();
    myqry->last();
    return *myqry;

}
QSqlQuery manage_all_books::best_User()
{

    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("SELECT COUNT ([main].[GetGive].[UserId]) AS [Count_UserId],"
           "[main].[GetGive].[UserId],"
           "[main].[Users].[fname],"
           "[main].[Users].[lname]"
    "FROM   [main].[GetGive]"
           "INNER JOIN [main].[Users] ON [main].[Users].[Code] = [main].[GetGive].[UserId]"
    "GROUP  BY [main].[GetGive].[UserId],"
              "[main].[Users].[fname],"
              "[main].[Users].[lname]"
    "ORDER  BY [Count_UserId] DESC;");

    myqry->exec();

   return *myqry;
}
QSqlQuery manage_all_books::best_Book()
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    myqry->prepare("SELECT COUNT ([main].[GetGive].[BookId]) AS [Count_BookId],"
       "[main].[Books].[Bookname]"
"FROM   [main].[Books]"
       "INNER JOIN [main].[GetGive] ON [main].[Books].[Book_Id] = [main].[GetGive].[BookId]"
"GROUP  BY [main].[Books].[Bookname]"
"ORDER  BY [Count_BookId] DESC;");
    myqry->exec();
   return *myqry;
}

double manage_all_books::percent()
{
    con_open();
    QSqlQuery * myqry= new QSqlQuery(msAccess);
    QSqlQuery * myqry_1= new QSqlQuery (msAccess);
    myqry->prepare(" select COUNT(DISTINCT BookId) from GetGive where Dategiveback IS NULL ");
    myqry->exec();
    myqry_1->prepare("select COUNT(Book_Id) from Books");
    myqry_1->exec();
    myqry->last();
    myqry_1->last();
    double percent= 100.0*(myqry->value(0).toDouble()/myqry_1->value(0).toDouble());
    return percent;
}
