#ifndef OPEN_DATABASE_HPP
#define OPEN_DATABASE_HPP
#include "QtSql"
#include "QString"
class open_database
{
public:

    QSqlDatabase msAccess =  QSqlDatabase::addDatabase("QSQLITE");
    QString sPath = "D:/information.db";

    open_database();
    bool con_open();
    void conclose();

};

#endif // OPEN_DATABASE_HPP
