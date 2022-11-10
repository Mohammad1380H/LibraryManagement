#ifndef MANAGE_ALL_BOOKS_HPP
#define MANAGE_ALL_BOOKS_HPP
#include "open_database.hpp"

class manage_all_books:public open_database
{
public:
    manage_all_books();
    QSqlQuery Borrowing (QString,QString);
    QString Deadline_left (QString);
    bool is_repated(QString);
    QSqlQuery return_book(QString,QString);
    bool is_his_book(QString,QString);
    int number_of_User_Books(QString);
    int number_of_Book_Users(QString);
    bool is_allowed_to_borrowed(QString , int);
    QSqlQuery List_of_User_books(QString);
    int number_of_book_now(QString);
    QSqlQuery Delayed_Users();
    QSqlQuery User_book(QString);
    QSqlQuery best_User();
    QSqlQuery best_Book();
    double percent();
};

#endif // MANAGE_ALL_BOOKS_HPP
