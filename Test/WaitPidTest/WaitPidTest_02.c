#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	unsigned int i;
	pid_t pid = 0,retPid = 0;
	pid_t pidArr[5] = {0};

	for(i=0;i<5;i++)
	{
		pid = fork();

		if(-1 == pid)
		{
			perror("创建子进程出错！\n");
			exit(-1);
		}else if(0 == pid)
		{
			break;
		}else
		{
			pidArr[i] = pid;
		}
	}

	if(i<5)
	{
		printf("第%d个子进程在这里循环!\n",i);
		while(1);
	}else
	{
		for(i=0;i<5;i++)
		{
			printf("第%d个子进程的PID是:%d\n",i,pidArr[i]);
		}
		for(i=0;i<5;i++);
		{
			retPid = waitpid(0,NULL,0);
			printf("子进程%d被回收!\n",retPid);

		}
	}

	return 0;
}
