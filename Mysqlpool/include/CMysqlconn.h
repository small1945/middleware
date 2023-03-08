#ifndef CMYSQLCONN_H_
#define CMYSQLCONN_H_
#include<mysql/mysql.h>

class Mysqlrecordset;
class Mysqlconn
{
    public:
        Mysqlconn(MYSQL*);
        ~Mysqlconn();
        Mysqlrecordset querySQL(const char*command);
        bool excuteSQL(const char*command);


    private:
        
        MYSQL* m_ptsql;
};



#endif