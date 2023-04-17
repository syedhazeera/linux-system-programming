//working of wait
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
 
int main()
{
    if (fork()== 0)
        printf("HC: hello from child\n");
    else
    {
        printf("HP: hello from parent\n");
        wait(NULL);
        printf("CT: child has terminated\n");
    }
 
    printf("Bye\n");
    return 0;
}

/*output:
syed@syed-VirtualBox:~/Desktop/linux$ gcc wait_work.c -o wait_work
syed@syed-VirtualBox:~/Desktop/linux$ ./wait_work
HP: hello from parent
HC: hello from child
Bye
CT: child has terminated
Bye*/