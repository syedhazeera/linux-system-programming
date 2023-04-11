#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void forkex()
{
	int x=1;
	if(fork() == 0)
	printf("child = %d\n",++x);
	else
	printf("parent =%d\n",--x);
}
int main()
{
	forkex();
return 0;
}

/*output:
LENOVO@DESKTOP-KCFUUP4 ~/linux
$ gcc int_fork.c -o int_fork

LENOVO@DESKTOP-KCFUUP4 ~/linux
$ ./int_fork
parent =0
child = 2

*/