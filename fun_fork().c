#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void fork()
{
	if(fork() == 0)
		printf("hii im child process\n");
	else
		printf("hii im parent process\n");
}
int main()
{
	fork();
return 0;
}

/*output:

*/