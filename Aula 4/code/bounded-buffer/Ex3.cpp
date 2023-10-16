#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 2

int shared_variable;
pthread_mutex_t mutex;
pthread_cond_t turn = PTHREAD_COND_INITIALIZER;

void *child_thread(void*) {
    int *id = (int *)arg;
    while (1) {
        pthread_mutex_lock(&mutex);
        while (shared_variable % THREADS != *id) {
            if (shared_variable == 1) {
                pthread_mutex_unlock(&mutex);
                return NULL;
            }
            pthread_cond_wait(&turn, &mutex);
        }
        if (shared_variable == 1) {
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
        shared_variable--;
        printf("Thread with ID %d decremented. Value: %d\n", *id, shared_variable);
        if (shared_variable == 1) {
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
        pthread_cond_broadcast(&turn);
        pthread_mutex_unlock(&mutex);
    }
}

int main(void) {
    int input;
    printf("Please enter a value between 10 and 20: ");
    scanf("%d", &input);

    // Input validation
    while (input < 10 || input > 20) {
        printf("Invalid input. Please enter a value between 10 and 20: ");
        scanf("%d", &input);
    }

    shared_variable = input;

    pthread_t threads[THREADS];
    int thread_ids[THREADS] = {0, 1};

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < THREADS; i++) {
        pthread_create(&threads[i], NULL, child_thread, &thread_ids[i]);
    }

    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&turn);
}
