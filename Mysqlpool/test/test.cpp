// #include"CMysqlpool.h"

 #include "CMysqlpool.h"
#include<vector>
#include<string.h>
#include<iostream>
#include"CMysqlconn.h"
#include"CMysqlrecordset.h"
using namespace std;
int main()
{
    Mysqlconnpool sqlpool;
    sqlpool.init();
    auto ptsql=sqlpool.getConnect();
    Mysqlconn conn(ptsql);
    auto result=conn.querySQL("select * from teacher");
    
    cout<<result.getItem("808","tname")<<endl;
    auto item=result.getItem("800","tname");
    if(item.size()!=0)
    {
        cout<<item<<endl;
    }
   

}