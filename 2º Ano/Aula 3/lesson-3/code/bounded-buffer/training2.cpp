#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include "process.h"

#define CHILD1_SEM 0
#define CHILD2_SEM 1

int main(void)
{
    int input;

    // create the semaphores for the odd numbers and the even number
    int sems = psemget(IPC_PRIVATE, 2, IPC_CREAT | 0600);

    do{

    printf("Insira um número entre 10 e 20: ");
    scanf("%d", &input);
    }while (input < 10 || input > 20);
    
    int shmid = pshmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0600);
    int *shared_counter = (int *)pshmat(shmid, NULL, 0);
    *shared_counter = input;
    printf("Start Value: %d\n", *shared_counter);
    psem_up(sems, CHILD1_SEM);

    pid_t pid_child1 = pfork();


    if(pid_child1 == 0){
        
        while(1){

            psem_down(sems, CHILD1_SEM);

            if(*shared_counter <= 1){
                psem_up(sems, CHILD2_SEM);
                break;
            }
            (*shared_counter)--;
            printf("Child 1 (PID: %d) decrementing: %d\n", getpid(), *shared_counter);
            sleep(1);
            psem_up(sems, CHILD2_SEM);
        }
        exit(0);
    }
    
    pid_t pid_child2 = pfork();

    if(pid_child2 == 0){
        
        while(1){

            psem_down(sems, CHILD2_SEM);

            if(*shared_counter <= 1){
                psem_up(sems, CHILD1_SEM);
                break;
            }
            (*shared_counter)--;
            printf("Child 2 (PID: %d) decrementing: %d\n", getpid(), *shared_counter);
            sleep(1);
            psem_up(sems, CHILD1_SEM);
        }
        exit(0);

    }else{

        pwaitpid(pid_child1, NULL, 0);
        pwaitpid(pid_child2, NULL, 0);

        pshmdt(shared_counter);
        pshmctl(shmid, IPC_RMID, NULL);

        psemctl(sems, 0, IPC_RMID);  // Remove o conjunto de semáforos
    
        printf("Parent process finished.\n");
    }

    return 0;
}