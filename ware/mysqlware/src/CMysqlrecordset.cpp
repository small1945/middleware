#include"CMysqlrecordset.h"

const std::string Mysqlrecordset::getItem(const std::string&value,const std::string&field)
{
    std::string temp;
    int col=_getFieldIndex(field);
    if(col==-1){printf("could not find\n");return temp;}
    int row=_getValueIndex(value);
    if(row==-1){printf("could not find\n");return temp;}
    
    temp=_getItem(row,col);
    return temp;
}


 int Mysqlrecordset::_getFieldIndex(const std::string&target)
{
    for(int i=0;i<fields.size();i++)
    {
        if(target==fields[i])
        {
            return i;
        }
    }
    return -1;
}

int Mysqlrecordset::_getValueIndex(const std::string&value)
{
    for(int i=0;i<rows.size();i++)
    {
        for(int j=0;j<rows[0].size();j++)
        {
            if(rows[i][j]==value)
            {
                return i;
            }
        }
    }
    return -1;
}

void Mysqlrecordset::clear()
{
    rows.clear();
    fields.clear();
}


const std::string& Mysqlrecordset:: _getItem(int row,int col)
{
    return rows[row][col];
}
