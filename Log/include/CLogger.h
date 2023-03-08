#ifndef CLOGGER_H_
#define CLOGGER_H_
#include"Logstream.h"
#include"CBufbase.h"
#include"CLogfile.h"
#include<functional>
class CLogger 
{
	public:

		using OutputCallBack=std::function<void(const char*, int)>;
		CLogger():m_thread(&CLogger::Output, this),m_bufferbase(new CRingBuffer(5000)),m_file(),m_state(State::INIT)
		{
			m_state.store(State::READY, std::memory_order_release);
		}
		void add(Logstream &stream)
		{
			m_bufferbase->push(std::move(stream));
		}
		
		~CLogger()
		{
			m_state.store(State::SHUTDOWN);
			m_thread.join();	
			delete m_bufferbase;
		}
		
		void setoutputCallBack(const OutputCallBack &func){m_outputFunc=func;}
		void Output()
		{
			while (m_state.load(std::memory_order_acquire) == State::INIT)
			{
			  std:: this_thread::sleep_for(std::chrono::microseconds(10));
			}

			Logstream stream;

			while (m_state.load() == State::READY)
			{
				if (m_bufferbase->try_pop(stream))
				{
					auto ptcontent = stream.GetContent();
					m_file.append(ptcontent, stream.bufLength());//write to file
					if(m_outputFunc){m_outputFunc(ptcontent, stream.bufLength());}
				}
				else
				{
					std::this_thread::sleep_for(std::chrono::microseconds(50));
				}
			}

			while (m_bufferbase->try_pop(stream))
			{
				auto ptcontent = stream.GetContent();
				m_file.append(ptcontent, stream.bufLength());//write to file
				//defaultOutput(ptcontent, stream.bufLength());
				if(m_outputFunc){m_outputFunc(ptcontent, stream.bufLength());}
			}
		}

		void defaultOutput(const char*content, int len)
		{
			fwrite(content, 1, len, stdout);
		}

	private:
		
		std::thread m_thread;
		CBufferBase *m_bufferbase;
		CLogfile m_file;
		enum class State
		{
			INIT,
			READY,
			SHUTDOWN
		};

		OutputCallBack m_outputFunc;
		std::atomic<State>m_state;

};


std::shared_ptr<CLogger>logger;
std::atomic<CLogger*>atomic_logger;

struct CLog
{
	void operator==(Logstream &stream)
	{
		atomic_logger.load(std::memory_order_acquire)->add(stream);
	}
};



void initalize()
{
	logger.reset(new CLogger());
	atomic_logger.store(logger.get());
}

#define LOG_INFO CLog()==Logstream(Logstream::Type::INFO)
#define LOG_ERROR CLog()==Logstream(Logstream::Type::ERR0R)
#define LOG_WARN CLog()==Logstream(Logstream::Type::WARN)


#endif
