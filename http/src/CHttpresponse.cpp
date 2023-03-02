#include"CHttpresponse.h"

Httpresponse::Httpresponse():
            m_servername(),
            m_statusStr(),
            m_statusCode(-1),
            m_body(),
            m_status(Status::NONE)
{

}

void  Httpresponse::setStatus(Status s)
{
    m_status=s;
    if(s==Status::BADREQUEST)
    {
        m_statusStr="Bad Request";
        m_statusCode=400;
    }
    else if(s==Status::ERROR)
    {}
    else if(s==Status::FORBIDDEN)
    {}
    else if(s==Status::NOTFOUND)
    {}
    else if(s==Status::OK)
    {
        
        m_statusStr="OK";
        m_statusCode=200;
    }
}
