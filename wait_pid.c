#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
 
void waitexample()
{
    int i, stat;
    pid_t pid[5];
    for (i=0; i<5; i++)
    {
        if ((pid[i] = fork()) == 0)
        {
            sleep(1);
            exit(100 + i);
        }
    }
 
    // Using waitpid() and printing exit status
    // of children.
    for (i=0; i<5; i++)
    {
        pid_t cpid = waitpid(pid[i], &stat, 0);
        if (WIFEXITED(stat))
            printf("Child %d terminated with status: %d\n",
                   cpid, WEXITSTATUS(stat));
    }
}
 
// Driver code
int main()
{
    waitexample();
    return 0;
}

/*output:
syed@syed-VirtualBox:~/Desktop/linux$ gcc wait_pid.c -o wait_pid
syed@syed-VirtualBox:~/Desktop/linux$ ./wait_pid
Child 4994 terminated with status: 100
Child 4995 terminated with status: 101
Child 4996 terminated with status: 102
Child 4997 terminated with status: 103
Child 4998 terminated with status: 104*/