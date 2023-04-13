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
PID of ex1.c = 61008
back to ex1.c
*/