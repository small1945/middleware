#include "Logstream.h"


Logstream& Logstream::operator<<(const std::string &str)
{
	std::string strtemp= str;
	buf.append(strtemp.data(), strtemp.size());
	return *this;
}


Logstream&Logstream::operator<<(int &num)
{
	auto strtemp=std::to_string(num);
	buf.append(strtemp.data(), strtemp.size());
	return *this;
}


void  Logstream::_formatStr()
{
	auto str=_formatType()+" ";
	std::string strtime = m_time.str();
	str+=strtime;
	str += ":";
	buf.append(str.data(), str.size());
}

std::string Logstream::_formatType()
{
	std::string retstr;
	switch (m_type)
	{
	case Type::INFO:
		retstr="[INFO]";
		break;
	case Type::ERR0R:
		retstr="[ERROR]";
		break;
	case Type::WARN:
		retstr="[WARN]";
		break;
	default:
		break;
	}
	return retstr;
}

