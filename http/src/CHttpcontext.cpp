#include "CHttpcontext.h"
#include "boost/make_shared.hpp"
Httpcontext::Httpcontext() : m_state(State::NONE), m_request(boost::make_shared<Httprequest>()),m_response(boost::make_shared<Httpresponse>()),result()
{
}

void Httpcontext::_parseReqBody(const char *ptbegin)
{
    if(m_request->methon()==Httprequest::Methon::GET)
    {
       m_request->setBody("");
       return;
    }
    auto ptend=ptbegin;
    while(*ptend!='\0')
    {
        ptend++;
    }
    string body(ptbegin,ptend);
    m_request->setBody(body);
}

void Httpcontext::_parseReqHead(const char *ptbegin, const char *ptend)
{
    if (*ptbegin == '\r' && *(ptbegin+1) == '\n'&&ptbegin==ptend)
    {
        _setState(State::REQBODY);
        return;
    }
    if (*ptbegin != 'C')
    {
        return;
    }

    auto ptc = ptbegin;
    while (*ptc != ':')
    {
        ptc++;
    }
    string headcontent(ptbegin, ptc - 1);

    if (headcontent == "")
    {
    }
    else if (headcontent == "")
    {
    }
}

void Httpcontext::_parseReqline(const char *ptbegin, const char *ptend)
{
    auto ptc = ptbegin;

    while (*ptc != ' ')
    {
        ptc++;
    }
    string methon(ptbegin, ptc);
    m_request->setMethon(methon);
    ptc=_parseblank(ptc);

    ptbegin = ptc;

    while (*ptc != ' ')
    {
        ptc++;
    }
     string url(ptbegin, ptc);
    m_request->setUrl(url);
    ptc=_parseblank(ptc);
    ptbegin=ptc;

    string version(ptbegin, ptend);
    m_request->setVersion(version);
    _setState(State::REQHEAD);
}

const char* Httpcontext::_parseline(const char *ptbegin)
{
    auto ptc = ptbegin;
    while (*ptc != '\r')
    {
        ptc++;
    }
    switch (m_state)
    {
    case State::REQLINE:
        _parseReqline(ptbegin, ptc);
        break;

    case State::REQHEAD:
        _parseReqHead(ptbegin, ptc);
        break;

    case State::REQBODY:
        _parseReqBody(ptbegin);
        break;
    }

    for (int i = 0; i < 2; i++)
    {
        ptc++;    
    }
    auto ptend=ptc;
    return ptend;
}

const char* Httpcontext::_parseblank( const char *ptc)
{
    while (*ptc == ' ')
    {
        ptc++;
    }
    return ptc;
 
}
void Httpcontext::_parse(const char *content)
{
    auto ptc = content;
    while (*ptc != '\0')
    {
        ptc=_parseline(ptc);
        if (m_state == State::REQBAD)
        {
            break;
        }
    }
}

bool Httpcontext::parseContent(const char *buf)
{
    _setState(State::REQLINE);
    _parse(buf);
    if (m_state == State::REQBAD)
    {
        return false;
    }
    return true;
}




void Httpcontext::initResponse(const string&servername,Httpresponse::Status s)
{
    m_response->setStatus(s);
    m_response->setServername(servername);
}




void Httpcontext::generateResponse()
{
    
    auto httpversion=m_request->version();
    auto statuscode=std::to_string(m_response->statusCode());
    auto status=m_response->status();
    const string responseLine=httpversion+" "+statuscode+" "+status+"\r\n";

    auto servername=m_response->serverName();
    const string reponseHead="Server:"+servername+"\r\n\r\n";

    string reponseBody;
    if(m_response->IsResponceOk())
    {
        reponseBody=m_response->body();
    }
   
   
    result+=responseLine;
    result+=reponseHead;
    result+=reponseBody;

}
