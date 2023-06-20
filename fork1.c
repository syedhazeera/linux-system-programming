#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
   fork();
   printf("Called fork() system call\n");
   return 0;
}

/*output:
syed@syed-VirtualBox:~/Desktop/linux$ ./fork1
Called fork() system call
syed@syed-VirtualBox:~/Desktop/linux$ Called fork() system call
*/