#include <stdio.h>
#include <sys/timeb.h>

int main(void)
{
	int m_ulRet = 0;
	struct timeb m_stTimeVal;

	m_ulRet = ftime(&m_stTimeVal);
	printf("     ret : %d\n",m_ulRet);
	printf("    time : %d\n"
		   " millitm : %d\n"
		   "timezone : %d\n"
		   " dstflag : %d\n",
		   (int)m_stTimeVal.time,
		   m_stTimeVal.millitm,
		   m_stTimeVal.timezone,
		   m_stTimeVal.dstflag);

	return 0;
}
