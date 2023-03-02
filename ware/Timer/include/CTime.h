#ifndef CTIME_H_
#define CTIME_H_
#include <time.h>
#include<string.h>
#include<string>

class CTime
{
public:
	CTime() :m_tm(),m_time(0),m_factsecond(0){
		
		_getTime();
	}
	CTime(int sec) :m_tm(),m_time(0), m_factsecond(sec)
	{
		_getTime();
	}

	~CTime() {  }
	 unsigned int getYear() const { return static_cast<int>(m_tm.tm_year+1900); }
	 unsigned int getMonth() const { return static_cast<int>(m_tm.tm_mon+1); }
	 unsigned int getDay() const { return static_cast<int>(m_tm.tm_mday); }
	 const char* str();
	 static CTime Now();
	 int getSecond()const { return m_factsecond; }

	
private:
	void _getTime();
	struct tm m_tm;
	time_t m_time;
	char m_strtime[30];
	struct timespec ts;
	int m_factsecond;


};


#endif
