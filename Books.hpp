#ifndef BOOKS_H
#define BOOKS_H
#include"open_database.hpp"

class Books :public open_database
{
public:
    Books();
    QSqlQuery search_Code_name_books(QString, QString);
    QSqlQuery search_Other_info_book(QString, QString);
    QSqlQuery show_pub(QString);
    QSqlQuery show_wrt(QString);
    QSqlQuery show_trs(QString);
    QSqlQuery save_info(QString,QString,QString,QString,QString);
    QSqlQuery edit_info(QString,QString,QString,QString,QString,QString);
    bool is_repated(QString );
    bool is_number(QString );
    bool is_Borrowed(QString);
QSqlQuery deletbook(QString );
//    QSqlQuery search_on_all_allocated_books(QString, QString, QString);
//    QSqlQuery saveinformations(QString, QString,QString,QString);
//    bool is_repated(QString );
//    bool check_len(QString,int);
//    bool is_number(QString );
//    QSqlQuery deleterec(QString);
//    QSqlQuery edit_informations(QString, QString,QString,QString,QString);
};

#endif // BOOKS_H
