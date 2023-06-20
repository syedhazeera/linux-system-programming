#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
   pid_t pid, mypid, myppid;
   pid = getpid();
   printf("Before fork: Process id is %d\n", pid);
   pid = fork();

   if (pid < 0) {
      perror("fork() failure\n");
      return 1;
   }

   // Child process
   if (pid == 0) {
      printf("This is child process\n");
      mypid = getpid();
      myppid = getppid();
printf("Process id is %d and PPID is %d\n", mypid, myppid);
   } else { // Parent process 
      sleep(2);
      printf("This is parent process\n");
      mypid = getpid();
      myppid = getppid();
      printf("Process id is %d and PPID is %d\n", mypid, myppid);
      printf("Newly created process id or child pid is %d\n", pid);
   }
   return 0;
}

/*output:
syed@syed-VirtualBox:~/Desktop/linux$ ./fork2
Before fork: Process id is 145191
This is child process
Process id is 145192 and PPID is 145191
This is parent process
Process id is 145191 and PPID is 139938
Newly created process id or child pid is 145192
*/