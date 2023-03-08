#include"CBuffer.h"


void Buffer::resize_if_need(size_t additional_bytes)
{
	size_t sumsize = m_bytes_used + additional_bytes;
	if (sumsize<m_buffer_size)
	{
		return;
	}

	m_buffer_size = (m_buffer_size * 2 > sumsize ? sumsize : m_buffer_size * 2);
	
	if (!m_head_buffer)
	{
		m_head_buffer.reset(new char[m_buffer_size]);
		memcpy(m_head_buffer.get(),m_stack_buffer,m_bytes_used);
	}
	else
	{
		std::unique_ptr<char[]>new_head_buffer(new char[m_buffer_size]);
		memcpy(new_head_buffer.get(), m_stack_buffer, m_bytes_used);
		m_head_buffer.swap(new_head_buffer);
	}


}
char* Buffer::buffer()
{
	return m_head_buffer ? m_head_buffer.get():m_stack_buffer;
}

 char *Buffer::WriteIndex()
{
	return m_head_buffer ? &m_head_buffer.get()[m_bytes_used] : &m_stack_buffer[m_bytes_used];
}
void Buffer::append(const char*content, size_t bytes)
{
	resize_if_need(bytes);
	 char *ptc = WriteIndex();
	memcpy(ptc, content, bytes);
	m_bytes_used += bytes;
}
