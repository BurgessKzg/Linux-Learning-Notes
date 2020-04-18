#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	struct timeval tv;
	system("date");
	gettimeofday(&tv,NULL);
	printf("timeval:%ld.%ld\n\n",tv.tv_sec,tv.tv_usec);
	
	tv.tv_sec = 1587039053;
	tv.tv_usec = 0;
	printf("timeval:%ld.%ld\n\n",tv.tv_sec,tv.tv_usec);
	
	if(settimeofday(&tv,NULL) != 0)
	{
		perror("settimeofday");	
	}
	system("date");
	gettimeofday(&tv,NULL);
	printf("timeval:%ld.%ld\n",tv.tv_sec,tv.tv_usec);
	
	return 0;
}
