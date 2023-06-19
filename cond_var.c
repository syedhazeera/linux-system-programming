#include <stdio.h>
#include <pthread.h>

int condition = 0;
pthread_mutex_t mutex;
pthread_cond_t cond_var;

void* check_condition(void* arg) {
    pthread_mutex_lock(&mutex);
    while (condition == 0) {
        pthread_cond_wait(&cond_var, &mutex);
    }
    printf("Condition is now true!\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* change_condition(void* arg) {
    // Simulating some computation
    sleep(2);

    pthread_mutex_lock(&mutex);
    condition = 1;
    pthread_cond_signal(&cond_var);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_var, NULL);

    pthread_create(&thread1, NULL, check_condition, NULL);
    pthread_create(&thread2, NULL, change_condition, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_var);

    return 0;
}

/*output:
syed@syed-VirtualBox:~/Desktop/linux$ ./cond_var
Condition is now true!
*/