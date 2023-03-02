#ifndef STRINGPIECE_H_
#define STRINGPIECE_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
class StringPiece
{
public:
	StringPiece(const char *str):m_ptr(str),m_length(strlen(m_ptr))
	{}
	StringPiece(const unsigned char*str) :m_ptr(reinterpret_cast<const char*>(str)), m_length(strlen(m_ptr)) {}
	StringPiece(const std::string &str) :m_ptr(str.data()), m_length(str.length()) {}
	const char* data()const { return m_ptr; }
private:
	const char *m_ptr;
	int  m_length;

};


#endif
