#include"CHttprequest.h"

Httprequest::Httprequest():
        m_methon(),
        m_url(),
        m_body(),
        m_version(),
        m_contentLen(0),
        m_IsKeepalive(false)
{

}


Httprequest::~Httprequest()
{

}

void Httprequest::setMethon(const string&m)
{
   if(m=="GET"){m_methon=Methon::GET;}
   else if(m=="POST"){m_methon=Methon::POST;}
   else{m_methon=Methon::NONE;}    
}
