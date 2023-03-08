#include "CTimerManager.h"
#include "boost/make_shared.hpp"
TimerManager::TimerManager()
    : m_queue(boost::make_shared<Timerqueue>())
{
}

TimerManager::~TimerManager()
{
}

/*
    sec:间隔时间
    func:绑定的任务函数
    IsRepeat:是否重复计时
    功能:增加定时任务
*/
void TimerManager::addTimer(int sec, const Timer::Callback &func, bool IsRepeat = false)
{
    Timer *timer = new Timer(func, sec);
    if (IsRepeat)
    {
        timer->setRepeat();
    }
    m_queue->add(timer);
}

void TimerManager::onHandle()
{
    m_queue->onHandle();
}

void TimerManager::init()
{
    m_queue->init();
}