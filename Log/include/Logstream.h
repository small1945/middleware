#ifndef LOGSTREAM_H_
#define LOGSTREAM_H_
#include <iostream>
#include <vector>
#include <string>
#include "CBuffer.h"
#include "CTime.h"
#include <thread>
#include <string>

class Logstream
{
public:
	enum class Type
	{
		INFO,
		ERR0R,
		WARN,
		EMPTY
	};
	Logstream() : buf(), m_time(), m_IsInput(0),m_type(Type::EMPTY)
	{
		//_formatStr();
	}
	Logstream(Type type) : buf(), m_time(), m_IsInput(0),m_type(type)
	{
		_formatStr();
	}
	
	Logstream &operator<<(const std::string &str);
	Logstream &operator<<(int &num);
	Logstream &operator=(Logstream &&) = default;
	Logstream(const Logstream &) = default;
	const char *GetContent() { return buf.buffer(); }
	int bufLength() const { return buf.size(); }
	Type getType()const{return m_type;}
	void setType(Type type){m_type=type;}
	

private:
	void _formatStr();
	std::string _formatType();
	Buffer buf;
	CTime m_time;
	bool m_IsInput;
	Type m_type;
};

#endif // !LOGSTREAM_H_
