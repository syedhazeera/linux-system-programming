#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int counter = 0;
sem_t semaphore;

void* increment(void* arg) {
    for (int i = 0; i < 10000; i++) {
        sem_wait(&semaphore);
        counter++;
        sem_post(&semaphore);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    sem_init(&semaphore, 0, 1);

    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, increment, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sem_destroy(&semaphore);

    printf("Counter value: %d\n", counter);

    return 0;
}

/*output:
syed@syed-VirtualBox:~/Desktop/linux$ ./sema
Counter value: 20000*/