#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
   fork();
   fork() && fork() || fork();
   fork();
  
   printf("forked\n");
   return 0;
}

/*output:
LENOVO@DESKTOP-KCFUUP4 ~/linux
$ gcc fork_bit.c -o fork_bit

LENOVO@DESKTOP-KCFUUP4 ~/linux
$ ./fork_bit
forked
forked
forked
forked
forked
forked
forked
forked
forked
forked
forked
forked
forked
forked
forked
forked
forked
forked
forked
forked

*/