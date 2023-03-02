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
    sec:���ʱ��
    func:�󶨵�������
    IsRepeat:�Ƿ��ظ���ʱ
    ����:���Ӷ�ʱ����
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