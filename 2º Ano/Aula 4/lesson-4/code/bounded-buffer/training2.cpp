#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <math.h>
#include <libgen.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "utils.h"
#include "thread.h"

int shared_counter;
pthread_mutex_t mutex;
pthread_cond_t cond1, cond2;
int turn = 1;

void *child_thread1(void *arg){
    
    while(shared_counter > 1){

        mutex_lock(&mutex);

        while(turn != 1){

            cond_wait(&cond1, &mutex);
        }

        if (shared_counter > 1){
            
            shared_counter--;
            printf("Thread 1 (PID: %lu) decrementing: %d\n", (unsigned long)thread_self, shared_counter);
        }

        turn = 2;

        cond_signal(&cond2);
        sleep(1);
        mutex_unlock(&mutex);
    }
    pthread_exit(NULL);

    return NULL;
}

void *child_thread2(void *arg){

    while(shared_counter > 1){

        mutex_lock(&mutex);

        while(turn != 2){

            cond_wait(&cond2, &mutex);
        }

        if (shared_counter > 1){
            
            shared_counter--;
            printf("Thread 2 (PID: %lu) decrementing: %d\n", (unsigned long)thread_self, shared_counter);
        }

        turn = 1;

        cond_signal(&cond1);
        sleep(1);
        mutex_unlock(&mutex);
    }
    pthread_exit(NULL);

    return NULL;
}

int main(void)
{
    
    int input;

    do{
        printf("Por favor insira um número inteiro entre 10 e 20: ");
        scanf("%d", &input);
    }while(input < 10 || input > 20);

    shared_counter = input;
            
    printf("Father (PID: %lu) starting: %d\n", (unsigned long)thread_self, shared_counter);

    mutex_init(&mutex, NULL);
    cond_init(&cond1, NULL);
    cond_init(&cond2, NULL);


    pthread_t first_thread, second_thread;
    pthread_create(&first_thread, NULL, child_thread1, NULL);
    pthread_create(&second_thread, NULL, child_thread2, NULL);

    pthread_join(first_thread, NULL);
    pthread_join(second_thread, NULL);

    mutex_destroy(&mutex);
    cond_destroy(&cond1);
    cond_destroy(&cond2);

    printf("Father Terminating!\n");

    return 0;
}