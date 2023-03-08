#ifndef CBUFBASE_H_
#define CBUFBASE_H_
#include "Logstream.h"
#include <atomic>
#include <stdlib.h>

class Spinlock
{
public:
	Spinlock(std::atomic_flag &f) : flag(f)
	{
		while (flag.test_and_set(std::memory_order_acquire))
			;
	}
	~Spinlock()
	{
		flag.clear(std::memory_order_release);
	}

private:
	std::atomic_flag &flag;
};

class CBufferBase
{
public:
	virtual ~CBufferBase() = default;
	virtual void push(Logstream &&stream) = 0;
	virtual bool try_pop(Logstream &stream) = 0;
};

class CRingBuffer : public CBufferBase
{
public:
	struct Item
	{
		Item() : IsWritten(0), stream(), flag{ATOMIC_FLAG_INIT} {}
		~Item() {}
		bool IsWritten;
		Logstream stream;
		std::atomic_flag flag;
	};
	CRingBuffer(const int size) : m_read_index(0), m_item(static_cast<Item *>(std::malloc(size * sizeof(Item)))),m_write_index(0),m_size(size)
	{

		for (int i = 0; i < size; i++)
		{
			new (&m_item[i]) Item();
		}
	}
	~CRingBuffer()
	{
		for (int i = 0; i < m_size; i++)
		{
			m_item[i].~Item();
		}

		free(m_item);
	}
	void push(Logstream &&stream) override
	{
		auto write_index = m_write_index.fetch_add(1, std::memory_order_relaxed) % m_size;
		Item &item = m_item[write_index];
		Spinlock lock(item.flag); 
		item.stream = std::move(stream);
		item.IsWritten = true;
	}

	bool try_pop(Logstream &stream) override
	{
		Item &item = m_item[m_read_index % m_size];
		Spinlock lock(item.flag);
		if (item.IsWritten == true)
		{
			stream = std::move(item.stream);
			item.IsWritten = false;
			++m_read_index;
			return true;
		}
		return false;
	}

private:
	unsigned int m_read_index;
	Item *m_item;
	std::atomic<unsigned int> m_write_index;
	const int m_size;
};

#endif