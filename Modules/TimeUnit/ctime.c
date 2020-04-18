#include <stdio.h>
#include <time.h>
#include <string.h> 
#include <stdlib.h>

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
	time_t m_tyTimeVal = 0;
	time_t m_tyTimeTempVal = 0;
	struct tm* m_pstTmVal;
	char *m_pucTimeStr;
	
	m_pstTmVal = malloc(sizeof(struct tm));
	m_pucTimeStr = malloc(200);

	printf("******************************** time() ***\n");
	m_tyTimeTempVal = time(NULL);
	printf("**%d\n",(int)m_tyTimeTempVal);
	
	printf("****************************** gmtime() ***\n");
	m_pstTmVal = gmtime(&m_tyTimeTempVal);
	printTm(m_pstTmVal);

	printf("*************************** localtime() ***\n");
	m_pstTmVal = localtime(&m_tyTimeTempVal);
	printTm(m_pstTmVal);
	
	printf("***************************** asctime() ***\n");
	m_pucTimeStr = asctime(m_pstTmVal); 
	printf("**%s",m_pucTimeStr);

	printf("******************************* ctime() ***\n");
	m_pucTimeStr = ctime(&m_tyTimeTempVal);
	printf("**%s",m_pucTimeStr);

	printf("****************************** mktime() ***\n");
	m_tyTimeVal = mktime(m_pstTmVal);
	printf("**%d\n",(int)m_tyTimeVal);
#if 0
	if(m_pstTmVal)
		free(m_pstTmVal);//Bk?:这里不能free,函数是怎么返回结构体指针的？
	if(m_pucTimeStr)
		free(m_pucTimeStr);
#endif

	return 0;
}
