#include <stdio.h>
#include <time.h>

void printTm(const struct tm* tm)
{
	printf("**%d-%d-%d:%d-%d-%d\n",tm->tm_year+1900,tm->tm_mon+1,\
			tm->tm_mday,tm->tm_hour,tm->tm_min,tm->tm_sec);
	printf("**week:%d\n",tm->tm_wday);
	printf("**yday:%d\n",tm->tm_yday);
	printf("**dst:%d\n",tm->tm_isdst);
}

int main(void)
{
	struct timespec timeVal;

	clock_gettime(CLOCK_REALTIME,&timeVal);
	printf("time:%s\n",ctime(&timeVal.tv_sec));
	printf("time: %ld.%ld\n",timeVal.tv_sec,timeVal.tv_nsec);

	return 0;
}
