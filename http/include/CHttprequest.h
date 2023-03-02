#ifndef CHTTPREQUEST_H_
#define CHTTPREQUEST_H_
#include<string>
using namespace std;

class Httprequest
{
    public:
       
        enum class Methon
        {
            GET,
            POST,
            NONE
        };
        Httprequest();
        ~Httprequest();
        void setUrl(const string&url){m_url=url;}
        void setMethon(const string&m);
        void setVersion(const string&version){m_version=version;}
        void setBody(const string&body){m_body=body;}
        void setContentLen(int len){m_contentLen=len;}
        void setKeepAlive(){m_IsKeepalive=true;}

        const string&body()const{return m_body;}
        const string&version()const{return m_version;}
        const string&url()const{return m_url;}
        const Methon&methon()const{return m_methon;}

    

    private:
        Methon m_methon;
        //std::string m_methon;
        std::string m_url;
        std::string m_body;
        std::string m_version;
        int m_contentLen;
        bool m_IsKeepalive;


};










#endif