#include "CMysqlpool.h"
#include <stdio.h>
#include<boost/make_shared.hpp>
const char *passwd = "asd1945";
const char *user = "root";
const char *database = "yourdb";
const unsigned int maxConnSum = 100;
const unsigned int minConnSum = 10;

Mysqlconnpool::Mysqlconnpool() : m_connectedSum(0)
{

}

void Mysqlconnpool::init()
{
    _initConn(minConnSum);
}

void Mysqlconnpool::_initConn(int sum)
{
    for(int i=0;i<minConnSum;i++)
    {
        auto tempconn=_init();
        if(!(_createConn(tempconn)))
        {printf("create error\n");}
        else
        {
            m_connlist.push_back(tempconn);
        }
    }
}

Mysqlconnpool::~Mysqlconnpool()
{
    for (auto conniter = m_connlist.begin(); conniter != m_connlist.end(); conniter++)
    {
        if (*conniter != NULL)
        {
            mysql_close(*conniter);
        }
    }
}

void Mysqlconnpool::releaseConn(MYSQL *mysql)
{
    m_connectedSum--;
    mysql_close(mysql);
}

MYSQL *Mysqlconnpool::getConnect()
{
    if (m_connectedSum >= maxConnSum)
    {
        printf("Mysqlconnections are max");
        return NULL;
    }
    else
    {
        if (m_connlist.empty())
        {
            int connSum = minConnSum;
            if (maxConnSum - m_connectedSum < minConnSum)
            {
                connSum = maxConnSum - m_connectedSum;
            }
            _initConn(connSum);
        }

        auto iter = m_connlist.begin();
        auto mysqlconn = *iter;
        m_connlist.erase(iter);
        m_connectedSum++;
        return mysqlconn;
    }
}

MYSQL* Mysqlconnpool::_createConn(MYSQL *mysql)
{
   return  mysql_real_connect(mysql, "localhost", user, passwd, database, 0, NULL, 0);  
}

MYSQL *Mysqlconnpool::_init()
{
    return mysql_init(NULL);
}
