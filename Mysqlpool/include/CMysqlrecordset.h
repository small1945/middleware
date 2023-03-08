#ifndef CMYSQLRECORDSET_H_
#define CMYSQLRECORDSET_H_
#include"mysql/mysql.h"
#include<vector>
#include<string>
#include"CMysqlconn.h"
class Mysqlrecordset
{
    public:
        friend class Mysqlconn;
        using FIELDS= std::vector<std::string>;
        using ROWS=std::vector<std::vector<std::string>>;
        
        Mysqlrecordset(){}
        ~Mysqlrecordset(){}
        const std::string getItem(const std::string&values,const std::string&field);
        void clear();

    private:

        int _getFieldIndex(const std::string&field);
        int _getValueIndex(const std::string&value);
        const std::string& _getItem(int row,int col);
       FIELDS fields;
       ROWS rows;


};











#endif