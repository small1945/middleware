#ifndef CMYSQLPOOL_H_
#define CMYSQLPOOL_H_
#include "mysql/mysql.h"
#include<list>
#include<boost/shared_ptr.hpp>
class Mysqlconnpool{


    public:
        Mysqlconnpool();
        ~Mysqlconnpool();
        void init();
        MYSQL* getConnect();
        void releaseConn(MYSQL* mysql);
        int connectedCount()const{return m_connectedSum;}

    private:
        int m_connectedSum;
        MYSQL* _init();
        MYSQL* _createConn(MYSQL*);
        void _initConn(int sum);
        std::list<MYSQL*> m_connlist;
       

};













#endif