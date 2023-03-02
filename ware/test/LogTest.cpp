#include "Logstream.h"
#include <algorithm>
#include<string>
#include"stringpiece.h"
#include<time.h>
#include"CTime.h"
#include<iostream>
#include"CLogfile.h"
#include"CBuffer.h"
#include<thread>
#include"CLogger.h"

using namespace std;


int main()
{
	// auto time = CTime::Now();
	// cout<<time.str();
	initalize();
	for(int i=0;i<500000;i++)
	{
		LOG_INFO<<"Log is running\n";
		LOG_ERROR<<"Log is quit\n";
		LOG_WARN<<"Log is warn\n";
	}
}
