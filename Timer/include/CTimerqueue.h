#ifndef CTIMEQUEUE_H_
#define CTIMEQUEUE_H_
#include"CTime.h"
#include"CTimer.h"
#include<set>
class Timerqueue
{
    public:
        Timerqueue();
        ~Timerqueue();
        void init();
        void add(Timer*);
        void del(Timer*);
        void onHandle();
        void setTime(int);
        bool updateIntervalTime(Timer*timer);
        int fd()const{return m_timerfd;}



    private:
       std::set<Timer*>m_timerQueue;
       int m_timerfd;
       int m_minInterval;
       
     
};









#endif