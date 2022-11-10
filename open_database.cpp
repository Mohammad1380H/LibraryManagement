#include "open_database.hpp"

open_database::open_database()
{

}

bool open_database::con_open()
{

       msAccess.setDatabaseName(sPath);
       msAccess.open();
       if(msAccess.isOpen())
       {
           return true;
       }
       else
       {
           return false;
       }
}
void open_database::conclose()
{

    msAccess.close();

    msAccess.removeDatabase(QSqlDatabase::defaultConnection);
}
