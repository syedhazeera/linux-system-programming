#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
 
int main()
{
    pid_t cpid;
    if (fork()== 0)
        exit(0);           /* terminate child */
    else
        cpid = wait(NULL); /* reaping parent */
    printf("Parent pid = %d\n", getpid());
    printf("Child pid = %d\n", cpid);
 
    return 0;
}

/*output:
syed@syed-VirtualBox:~/Desktop/linux$ gcc wait.c -o wait
syed@syed-VirtualBox:~/Desktop/linux$ ./wait
Parent pid = 3475
Child pid = 3476*/
