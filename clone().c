#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/sched.h>
#include <signal.h>
#include <sys/syscall.h>

#define STACK 8192

int do_something(){
        printf("Child pid : %d\n", getpid());
        return 0;
}

int main() {
        void *stack = malloc(STACK);    // Stack for new process

        if(!stack) {
                perror("Malloc Failed");
                exit(0);
        }

        if( clone( &do_something, (char *)stack + STACK, CLONE_VM, 0) < 0 ){
                perror("Clone Failed");
                exit(0);
        }

        printf("Parent pid : %d\n", getpid());

        sleep(1);       // Add sleep so we can see both processes output

        free(stack);

        return 0;
}

/*OUTPUT:
syed@syed-VirtualBox:~/Desktop/linux$ ./clone
parent pid : 4367
child pid : 4368
*/