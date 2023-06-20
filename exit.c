#include <stdio.h>
#include <stdlib.h>

void exitfunc() {
   printf("Called cleanup function - exitfunc()\n");
   return;
}

int main() {
   atexit(exitfunc);
   printf("Hello, World!\n");
   exit (0);
}

/*output:
syed@syed-VirtualBox:~/Desktop/linux$ ./exit
Hello, World!
Called cleanup function - exitfunc()
*/