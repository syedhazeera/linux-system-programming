#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
 
int main()
{
    char c;
    int fd1 = open("sample.txt", O_RDONLY, 0);
    int fd2 = open("sample.txt", O_RDONLY, 0);
    read(fd1, &c, 1);
    read(fd2, &c, 1);
    printf("c = %c\n", c);
    exit(0);
}

/*output:
syed@syed-VirtualBox:~/Desktop/linux$ gcc read1.c -o read1
syed@syed-VirtualBox:~/Desktop/linux$ ./read1
c = h
*/