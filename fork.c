#include <stdio.h>
#include <unistd.h>

int main(void)
{
        pid_t pid = fork();

        if( pid > 0 )
                printf("Parent Process: ParentPID = %d, ChildPID  = %d\n", getpid(), pid);
        else
                printf("Child  Process: ChildPID  = %d, ParentPID = %d\n", getpid(), pid);

        sleep(2);

        return 0;
}

/*output:
Parent Process: ParentPID = 4465, ChildPID = 4466
Child  Process: ChildPID  = 4466, ParentPID = 0
*/