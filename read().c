// read system Call
#include<stdio.h>
#include <fcntl.h>
#include<stdlib.h>
int main()
{
int fd, sz;
char *c = ((char *) calloc(100, sizeof(char));
 
fd = open("foo.txt", O_RDONLY);
if (fd < 0) { perror("r1"); exit(1); }
 
sz = read(fd, c, 10);
printf("called read(% d, c, 10). returned that"
        " %d bytes were read.\n", fd, sz);
c[sz] = '\0';
printf("Those bytes are as follows: % s\n", c);
}

/*output:
syed@syed-VirtualBox:~/Desktop/linux$ ./read
called read( 3, c, 10). returned that 10 bytes were read.
Those bytes are as follows: hello haze*/