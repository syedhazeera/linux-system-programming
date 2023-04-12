//to know pid
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	printf("this is hazeera!\n PID = %d\n",getpid());
return 0;
}

/*output:
hello this is hazeera!
PID = 22229
*/