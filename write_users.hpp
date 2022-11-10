#ifndef WRITE_USERS_HPP
#define WRITE_USERS_HPP
#include "open_database.hpp"

class write_users : public open_database
{
public:
    write_users();
    QSqlQuery addaccount(QString, QString, QString );
};

#endif // WRITE_USERS_HPP
