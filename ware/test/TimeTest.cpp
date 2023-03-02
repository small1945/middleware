


#include"CTime.h"






int main()
{
    for(int i=0;i<100000000;i++)
    {
	    auto time=CTime::Now();
        printf("%d\n",time.getSecond());
    }
   
}
