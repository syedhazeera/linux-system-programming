#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int a;
	printf("enter value of a:\n");
	scanf("%d",&a);
	if (fork() == 0)
	{
    	a = (a + 5);
    	printf("%d, %d\n", a, &a);
	}
	else
	{
    	a = (a - 5);
    	printf("%d, %d\n", a, &a);
	}
return 0;
}

/*output:
LENOVO@DESKTOP-KCFUUP4 ~/linux
$ gcc fork_exp.c -o fork_exp

LENOVO@DESKTOP-KCFUUP4 ~/linux
$ ./fork_exp
enter value of a:
8
3, -13268
13, -13268
*/
