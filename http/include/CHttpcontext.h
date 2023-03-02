#ifndef CHTTPCONTEXT_H_
#define CHTTPCONTEXT_H_
#include"CHttprequest.h"
#include"CHttpresponse.h"
#include<boost/shared_ptr.hpp>
class Httpcontext
{
    public:
        enum class State
        {
            REQLINE,
            REQHEAD,
            REQBODY,
            REQBAD,
            REQSUCESS,
            NONE
        };
        Httpcontext();
        ~Httpcontext(){}

        bool parseContent(const char*buf);
        const Httprequest& getRequst()const{return *m_request.get();}

        void generateResponse();
        void initResponse(const string&servername,Httpresponse::Status s);
        void setResponseBody(const string&body){m_response->setBody(body);}
        const string&getResponse(){return result;}
    private:
        void _setState(State state){m_state=state;}
        void _parse(const char*);
        const char* _parseblank(const char*);
        const char* _parseline(const char*);
        void _parseReqline(const char*,const char*);
        void _parseReqHead(const char*,const char*);
        void _parseReqBody(const char*);
        State m_state;
        boost::shared_ptr<Httprequest>m_request;
        boost::shared_ptr<Httpresponse>m_response;
        string result;
        
};






#endif