#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#define SIZE 5
int nums[SIZE] = {0, 1, 2, 3, 4};
int main()
{
        int i;
        pid_t pid;
        pid = vfork();
        if(pid == 0){  /* Child process */
                for(i = 0; i < SIZE; i++){
                        nums[i] *= -i;
                        printf("CHILD: %d \n", nums[i]);
                }
                _exit(0);
        }
        else if (pid > 0){  /* Parent process */
                wait(NULL);
                for(i = 0; i < SIZE; i++)
                        printf("PARENT: %d \n", nums[i]);
        }
        return 0;
}
/*OUTPUT:
Parent :1
Parent :2
Parent :3
Parent :4
Parent :0
*/