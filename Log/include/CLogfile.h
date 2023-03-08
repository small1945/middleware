#ifndef CLOGFILE_H_
#define CLOGFILE_H_
#include<stdio.h>
#include"CTime.h"
#include<string>
#include<mutex>
#include<memory>

class CLogfile
{
public:
	static int ROLLSIZE;
	CLogfile():m_time(), m_rollsize(ROLLSIZE), rollflag(5) 
	{
		m_mutex.reset(new std::mutex);
		m_file = new File(GetfileName("")); 
	}
	CLogfile(int maxsize,int rollflag);
	~CLogfile() { delete m_file; }
	std::string GetfileName(const std::string& );
	void RollFile();
	void append(const char* content, int len);


private:

	
	class File
	{
		public:
			File(const std::string filename):m_writebytes(0)
			{
				file=fopen(filename.data(),"a");
			}
			~File()
			{
				fclose(file);
			}

			void append(const char* content,int len);
			size_t WriteBytes()const { return m_writebytes; }
			FILE *file;

		private:
			
			size_t m_writebytes;

	};

	File* m_file;
	CTime m_time;
	size_t m_rollsize;
	char m_filename[30];
	int rollflag;
	std::unique_ptr<std::mutex>m_mutex;
	

};




#endif