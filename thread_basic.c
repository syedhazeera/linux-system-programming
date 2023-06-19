#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *thread_func(void  *arg);
int i,n,j;
int main()
{
	pthread_t a_thread;
	pthread_create(&a_thread, NULL,thread_func, NULL);
	pthread_join(a_thread,NULL);
	printf("inside main program\n");
	for(j=20;j<25;j++)
	{
		printf("%d\n",j);
		sleep(1);
	}
}
void *thread_func(void *arg)
{
	printf("inside thread\n");
	for(i=0;i<5;i++)
	{
		printf("%d\n",i);
		sleep(1);
	}
}

/*output:
syed@syed-VirtualBox:~/Desktop/linux$ ./thread_basic
inside thread
0
1
2
3
4
inside main program
20
21
22
23
24
*/