#include<stdio.h>
#include <fcntl.h>
#include<stdlib.h>
int main()
{
    int fd1 = open("foo.txt", O_RDONLY);
    if (fd1 < 0)
    {
        perror("c1");
        exit(1);
    }
    printf("opened the fd = % d\n", fd1);
     
    // Using close system Call
    if (close(fd1) < 0)
    {
        perror("c1");
        exit(1);
    }
    printf("closed the fd.\n");
}

/*output:
syed@syed-VirtualBox:~/Desktop/linux$ ./close
opened the fd =  3
closed the fd.*/
