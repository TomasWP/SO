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

int shared_counter;  // Alocar memória para shared_counter


void *child_thread(void *arg){

    int child_input;

    do{
        printf("Por favor insira um número inteiro entre 10 e 20: ");
        scanf("%d", &child_input);
    }while(child_input < 10 || child_input > 20);

    while(shared_counter < child_input){
        (shared_counter)++;
        printf("Child incrementing: %d\n", shared_counter);
        sleep(1);
    }

    thread_exit(NULL);
    return NULL;
}

int main(void)
{
    
    int input;

    do{
        printf("Por favor insira um número inteiro entre 1 e 9: ");
        scanf("%d", &input);
    }while(input < 1 || input > 9);

    shared_counter = input;

    printf("Main Start: %d\n", shared_counter);

    while(shared_counter > 1){
        (shared_counter)--;
        printf("Decrementing: %d\n", shared_counter);
        sleep(1);
    }

    pthread_t new_thread;
    thread_create(&new_thread, NULL, child_thread, NULL);

    thread_join(new_thread, NULL);
    printf("Main Terminating!\n");

    return 0;
}