#ifndef USERS_H
#define USERS_H
#include"open_database.hpp"
#include "QMessageBox"
class Users:public open_database
{
public:
    Users();


    QSqlQuery search_Idname(QString, QString, QString);
    QSqlQuery search_on_pictures(QString, QString, QString);
    QSqlQuery search_on_all_allocated_books(QString, QString, QString);
    QSqlQuery saveinformations(QString, QString,QString,QString);
    bool is_repated(QString );
    bool check_len(QString,int);
    bool is_number(QString );
    bool is_have_book(QString);
    QSqlQuery deleterec(QString);
    QSqlQuery edit_informations(QString, QString,QString,QString,QString);
};

#endif // USERS_H
