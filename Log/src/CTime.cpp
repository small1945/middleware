#include"CTime.h"
#include <time.h>
 void CTime::_getTime()
{
	time(&m_time);
	auto ptm=gmtime(&m_time);
	m_tm=*ptm;
	m_tm.tm_hour += 8;
}

 const char * CTime::str()
 {	
	 strftime(m_strtime, sizeof(m_strtime), "%Y-%m-%d %H:%M:%S", &m_tm);
	 return m_strtime;
 }

 CTime CTime::Now()
 {
	 time_t timep;
	 time(&timep);
	 return CTime(timep);
 }