#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argv,char* argc[])
{
	unsigned int i;
	pid_t pid = 0;

	pid = fork();
	if(-1 == pid)
	{
		perror("创建子进程出错！\n");
		exit(-1);
	}else if(0 == pid)
	{
		printf("子进程任务!\n");
		while(-1);
		printf("子进程任务结束!\n");
	}else
	{
		printf("父进程回收非血缘进程!\n");
		if(-1 == waitpid(5455,NULL,0))
		{
			perror("回收非血缘进程失败!\n");
		}

		waitpid(pid,NULL,0);
	}

	return 0;
}
