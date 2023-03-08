#include "CMysqlconn.h"
#include<vector>
#include<string>
#include"CMysqlrecordset.h"

Mysqlconn::Mysqlconn(MYSQL *conn) : m_ptsql(conn)
{

}

Mysqlconn::~Mysqlconn()
{

}

bool Mysqlconn::excuteSQL(const char*command)
{
     if (mysql_query(m_ptsql, command))
    {
        printf("sql fail\n");
        return false;
    }
    return true;
}


Mysqlrecordset Mysqlconn::querySQL(const char *command)
{
    Mysqlrecordset  recordset;
    if (!excuteSQL(command))
    {
        return recordset;
    }

    auto result = mysql_store_result(m_ptsql);
    int cols=mysql_num_fields(result);
    int lines=mysql_num_rows(result);

    
    MYSQL_FIELD* field=nullptr;
    while(field=mysql_fetch_field(result))
    {
        recordset.fields.push_back(field->name);
    }


    MYSQL_ROW rowres;
    recordset.rows.reserve(lines);
     while(rowres=mysql_fetch_row(result))
    {
        std::vector<std::string>row;
        row.resize(cols);
        for(int i=0;i<cols;i++)
        {
            if(rowres[i])
            {
              row[i]=rowres[i];
            }
            else
            {
                row[i]="";
            }
        }
        recordset.rows.push_back(row);
    }

}
