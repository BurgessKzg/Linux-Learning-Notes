#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t m_tyTimeVal = 0;

	m_tyTimeVal = time(NULL);
	printf("%d\n",(int)m_tyTimeVal);

	return 0;
}
