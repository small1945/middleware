#include"CTimer.h"
#include"CTime.h"
bool Timer::judgeExpire()
{
    auto nowtime=CTime::Now();
    if(nowtime.getSecond()>=m_begSecond+m_seq)
    {
        return true;
    }
    return false;
}
