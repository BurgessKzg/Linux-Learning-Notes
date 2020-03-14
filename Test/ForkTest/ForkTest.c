#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argv,char* argc[])
{
	unsigned int i,cnt;
	pid_t pid = 0;

	if(argv < 2)
	{
		printf("请传入创建子进程个数参数！\n");
		exit(-1);
	}
	printf("进程开始!\n");
	
	cnt = strtol(argc[1],NULL,10);
	printf("要创建的子进程个数为：%d\n",cnt);
	for(i=0;i<cnt;i++)
	{
		pid = fork();

		if(-1 == pid)
		{
			perror("创建子进程出错！\n");
			exit(-1);
		}
		if(0 == pid)
		{
			break;
		}
	}
	
	sleep(i);

	if(i<cnt)
	{
		
		printf("我是第%d个子进程\n",i+1);
	}else
	{
		printf("我是父进程！\n");
	}

	return 0;
}

