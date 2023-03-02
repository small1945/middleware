#ifndef CHTTPRESPONSE_H_
#define CHTTPRESPONSE_H_
#include<string>
#include<CHttprequest.h>
using namespace std;

class Httpresponse
{
    public:
        enum class Status
        {
            OK,
            NOTFOUND,
            BADREQUEST,
            FORBIDDEN,
            ERROR,
            NONE
        };
        Httpresponse();
        ~Httpresponse(){}
        void setServername(const string&name){m_servername=name;}
        void setBody(const string&body){m_body=body;}
        void setStatus(Status s);
        int  statusCode()const{return m_statusCode;}
        const string&serverName()const{return m_servername;}
        const string&status()const{return m_statusStr;}
        const string&body()const{return m_body;}
        bool IsResponceOk()const{return m_status==Status::OK;}
    
    private:
      
        string m_servername;
        string m_statusStr;
        int m_statusCode;
        string m_body;
        Status m_status;

};




#endif