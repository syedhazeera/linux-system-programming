#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5
#define NUM_PRODUCERS 2
#define NUM_CONSUMERS 2
#define NUM_ITEMS 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t mutex;
sem_t full;
sem_t empty;

void* producer(void* arg) {
    int producer_id = *(int*)arg;

    for (int i = 0; i < NUM_ITEMS; i++) {
        int item = i + (producer_id * NUM_ITEMS);

        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = item;
        printf("Producer %d produced item %d\n", producer_id, item);
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&full);
    }

    return NULL;
}

void* consumer(void* arg) {
    int consumer_id = *(int*)arg;

    for (int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(&full);
        sem_wait(&mutex);

        int item = buffer[out];
        printf("Consumer %d consumed item %d\n", consumer_id, item);
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&empty);
    }

    return NULL;
}

int main() {
    pthread_t producers[NUM_PRODUCERS];
    pthread_t consumers[NUM_CONSUMERS];

    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUFFER_SIZE);

    int producer_ids[NUM_PRODUCERS];
    int consumer_ids[NUM_CONSUMERS];

    for (int i = 0; i < NUM_PRODUCERS; i++) {
        producer_ids[i] = i;
        pthread_create(&producers[i], NULL, producer, &producer_ids[i]);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++) {
        consumer_ids[i] = i;
        pthread_create(&consumers[i], NULL, consumer, &consumer_ids[i]);
    }

    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(producers[i], NULL);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(consumers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);

    return 0;
}

/*output:
syed@syed-VirtualBox:~/Desktop/linux$ ./sem_pro_con
Producer 1 produced item 10
Producer 1 produced item 11
Producer 1 produced item 12
Producer 1 produced item 13
Producer 1 produced item 14
Consumer 1 consumed item 10
Consumer 1 consumed item 11
Consumer 1 consumed item 12
Consumer 1 consumed item 13
Consumer 0 consumed item 14
Producer 1 produced item 15
Producer 1 produced item 16
Producer 1 produced item 17
Producer 1 produced item 18
Producer 1 produced item 19
Consumer 0 consumed item 15
Consumer 0 consumed item 16
Consumer 0 consumed item 17
Consumer 0 consumed item 18
Consumer 1 consumed item 19
Producer 0 produced item 0
Producer 0 produced item 1
Producer 0 produced item 2
Producer 0 produced item 3
Producer 0 produced item 4
Consumer 1 consumed item 0
Consumer 1 consumed item 1
Consumer 1 consumed item 2
Consumer 1 consumed item 3
Consumer 0 consumed item 4
Producer 0 produced item 5
Producer 0 produced item 6
Producer 0 produced item 7
Producer 0 produced item 8
Producer 0 produced item 9
Consumer 0 consumed item 5
Consumer 0 consumed item 6
Consumer 0 consumed item 7
Consumer 0 consumed item 8
Consumer 1 consumed item 9
*/