#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include "process.h"

int main(void)
{
    int shmid, *shared_counter;

    /* create the shared memory and init it as a rint  */
    shmid = pshmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0600);

    // Attach shared memory segment to address space
    shared_counter = (int *)pshmat(shmid, NULL, 0);

    *shared_counter = 1;

    pid_t pid = pfork();

    if (pid == 0){

        int input;
        do{
            printf("Por favor insira um número inteiro entre 10 e 20: ");
            scanf("%d", &input);
        }while(input < 10 || input > 20);

        printf("Child Start: %d\n", *shared_counter);

        while(*shared_counter < input){
            (*shared_counter)++;
            printf("Child incrementing: %d\n", *shared_counter);
            sleep(1);
        }

        // Detach shared memory
        shmdt(shared_counter);
        printf("Child process finished.\n");

        exit(0);  // Child process terminates
    }else{

        pwait(NULL);
        while(*shared_counter > 1){
            (*shared_counter)--;
            printf("Parent decrementing: %d\n", *shared_counter);
            sleep(1);
        }

        // Detach shared memory
        shmdt(shared_counter);

        // Release the shared memory
        shmctl(shmid, IPC_RMID, NULL);

        printf("Parent process finished.\n");
    }

    return 0;
}