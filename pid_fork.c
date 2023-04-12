//pid using fork()
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	fork();
	printf("this is hazeera!\n PID = %d\n",getpid());
return 0;
}