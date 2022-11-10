#ifndef WTP_H
#define WTP_H
#include "QSqlQuery"
#include "open_database.hpp"
class wtp:public open_database
{
public:
    wtp();
    QSqlQuery addwrt(QString,QString,QString,bool);
    QSqlQuery addtrs(QString,QString,QString,bool);
    QSqlQuery addpub(QString);

};

#endif // WTP_H
