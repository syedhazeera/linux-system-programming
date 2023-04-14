#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	printf("PID of ex1.c = %d\n",getpid());
	char *args[]={"hii","this","is","hazeera",NULL};
	execv("./ex2",args);
	printf("back to ex1.c");
	return 0;
}

/*output:
$ gcc exec.c -o exec
$ gcc ex2.c -o ex2
$ ./exec
PID of ex1.c = 903
we are in ex2.c
PID of ex2.c = 903

$ ./ex2
we are in ex2.c
PID of ex2.c = 904

*/
