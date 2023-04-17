#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
main()
{
int semid,pid;
struct sembuf sop;
semid=semget(0*20,1,IPC_CREAT|0666);
semctl(semid,0,SETVAL,1);
pid=fork();
if(pid!=0)
{
printf("\n child before semaphore\n");
sop.sem_num=0;
sop.sem_op=-1;
sop.sem_flg=0;
semop(semid,&sop,1);
printf("\n child in critical section\n");
sleep(2);
printf("\n child in critical section \n");
sop.sem_num=0;
sop.sem_op=1;
sop.sem_flg=0;
semop(semid,&sop,1);
}
else
{
printf("\n parent before semaphore \n");
sop.sem_num=0;
sop.sem_op=-1;
sop.sem_flg=0;
semop(semid,&sop,1);
printf("\n parent in critical section");
sleep(2);
printf("\n parent coming out of critical section");
sop.sem_num=0;
sop.sem_op=1;
sop.sem_flg=0;
semop(semid,&sop,1);
}
}

/*output:
syed@syed-VirtualBox:~/Desktop/linux$ gcc sem.c -o sem
syed@syed-VirtualBox:~/Desktop/linux$ ./sem

 child before semaphore

 child in critical section

 parent before semaphore 

 child in critical section 
syed@syed-VirtualBox:~/Desktop/linux$ 
 parent in critical section
 parent coming out of critical section
*/