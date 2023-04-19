#include <stdio.h>
#include <pthread.h>

#define NTHREADS 10
void *thread_function(void *);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int  counter = 0;

main()
{
   pthread_t thread_id[NTHREADS];
   int i, j;

   for(i=0; i < NTHREADS; i++)
   {
      pthread_create( &thread_id[i], NULL, thread_function, NULL );
   }

   for(j=0; j < NTHREADS; j++)
   {
      pthread_join( thread_id[j], NULL); 
   }
  
   /* Now that all threads are complete I can print the final result.     */
   /* Without the join I could be printing a value before all the threads */
   /* have been completed.                                                */

   printf("Final counter value: %d\n", counter);
}

void *thread_function(void *dummyPtr)
{
   printf("Thread number %ld\n", pthread_self());
   pthread_mutex_lock( &mutex1 );
   counter++;
   pthread_mutex_unlock( &mutex1 );
}

/*output:
	syed@syed-VirtualBox:~/Desktop/linux$ gcc -lpthread join.c
syed@syed-VirtualBox:~/Desktop/linux$ ./a.out
Thread number 140197930985024
Thread number 140197922592320
Thread number 140197914199616
Thread number 140197905806912
Thread number 140197897414208
Thread number 140197889021504
Thread number 140197880628800
Thread number 140197939377728
Thread number 140197872236096
Thread number 140197863843392
Final counter value: 10
*/