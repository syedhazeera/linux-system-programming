// CPP program to illustrate dup2() 
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
  
int main()
{
    int file_desc = open("tricky.txt",O_WRONLY | O_APPEND);
      
    // here the newfd is the file descriptor of stdout (i.e. 1)
    dup2(file_desc, 1) ; 
          
    // All the printf statements will be written in the file
    // "tricky.txt"
    printf("I will be printed in the file tricky.txt\n");
      
return 0;
}

/*output:
syed@syed-VirtualBox:~/Desktop/linux$ gcc duplicate2.c -o duplicate2
syed@syed-VirtualBox:~/Desktop/linux$ ./duplicate2
syed@syed-VirtualBox:~/Desktop/linux$ vim tricky.txt

hii mempage
I will be printed in the file tricky.txt
*/