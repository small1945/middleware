#include "CLogfile.h"

int CLogfile::ROLLSIZE=1000*1000;
void CLogfile::File::append(const char* content,int len)
{   
	auto size=fwrite(content,1, len, file);
	m_writebytes += size;
}

CLogfile::CLogfile(int maxsize,int flag):m_time(),m_rollsize(maxsize),rollflag(flag)
{ 
	m_file = new File(GetfileName(""));
}

 std::string CLogfile::GetfileName(const std::string &basename)
{
	std::string filename;
	char timebuf[30];
	filename.reserve(30);
	filename += basename;
	int year = m_time.getYear();
	int month = m_time.getMonth();
	int day = m_time.getDay();
	snprintf(timebuf,sizeof(m_filename),"%d-%d-%d.log",year,month,day);
	filename += timebuf;
	return filename;
}

 void CLogfile::append(const char*content,int len)
 {
	// std::lock_guard<std::mutex> lock(*m_mutex);
	 RollFile();
	 m_file->append(content, len);
 }


 void CLogfile::RollFile()
 {
	 auto filesize=ftell(m_file->file);

	 if (m_file->WriteBytes()+filesize> m_rollsize)
	 {
		 auto ptfile = m_file;
		 delete ptfile;
		 std::string fname = "roll_" + std::to_string(rollflag++)+".";
		 m_file = new File(GetfileName(fname));
	  }
 }

