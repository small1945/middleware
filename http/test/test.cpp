#include"CHttpcontext.h"
#include"CHttpresponse.h"
#include<iostream>
using namespace std;
const char *httprequest = "POST /root/build.sh HTTP/1.1\r\nHost: 127.0.0.1:8000\r\nUser-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:99.0) Gecko/20100101 Firefox/99.0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8\r\nAccept-Language: en-US,en;q=0.5\r\nAccept-Encoding: gzip, deflate, br\r\nConnection: keep-alive\r\nUpgrade-Insecure-Requests: 1\r\nSec-Fetch-Dest: document\r\nSec-Fetch-Mode: navigate\r\nSec-Fetch-Site: none\r\nSec-Fetch-User: ?1\r\n\r\nshow me the way";

int main()
{
    Httpcontext context;
    context.parseContent(httprequest); 
    auto request=context.getRequst();
    cout<<"requese is:"<<" "<<request.url()<<" "<<request.version()<<" "<<request.body()<<endl;
    
    context.initResponse("muduo",Httpresponse::Status::OK);
    context.setResponseBody("hello world");
    context.generateResponse();
    cout<<"response is:\n"<< context.getResponse()<<endl;

}