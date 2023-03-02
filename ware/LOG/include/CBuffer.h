#ifndef CBUFFER_H_
#define CBUFFER_H_
#include<memory>
#include<string.h>
class Buffer
{
	public:
		Buffer() :m_bytes_used(0), m_buffer_size(sizeof(m_stack_buffer)) {}
		void resize_if_need(size_t additional_bytes);
		char *buffer() ;
	    char* WriteIndex() ;
		void append(const char*,size_t bytes);
		size_t size() const { return m_bytes_used; }


private:
	size_t m_bytes_used;
	size_t m_buffer_size;
	std::unique_ptr<char[]>m_head_buffer;
	char m_stack_buffer[256];



};









#endif