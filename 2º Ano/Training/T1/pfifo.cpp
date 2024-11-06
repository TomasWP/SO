#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pfifo.h"
#include "thread.cpp"

// Inicializa o FIFO
void pfifo_init(pfifo_t* fifo, int capacity) {
    fifo->buffer = (int*)malloc(sizeof(int) * capacity);
    fifo->capacity = capacity;
    fifo->size = 0;
    fifo->front = 0;
    fifo->rear = 0;
    mutex_init(&fifo->mutex, NULL);
    cond_init(&fifo->notEmpty, NULL);
    cond_init(&fifo->notFull, NULL);
}

// Libera recursos do FIFO
void pfifo_free(pfifo_t* fifo) {
    free(fifo->buffer);
    mutex_destroy(&fifo->mutex);
    cond_destroy(&fifo->notEmpty);
    cond_destroy(&fifo->notFull);
}

// Adiciona um carro ao FIFO
void pfifo_push(pfifo_t* fifo, int car_id) {

    mutex_lock(&fifo->mutex);
    while(pfifo_is_full(fifo)){
        cond_wait(&fifo->notFull, &fifo->mutex);
    }
    if (fifo->size < fifo->capacity) {
        fifo->buffer[fifo->rear] = car_id;
        fifo->rear = (fifo->rear + 1) % fifo->capacity;
        fifo->size++;
    } else {
        printf("FIFO está cheio, carro %d não pode entrar na fila.\n", car_id);
    }
    cond_broadcast(&fifo->notEmpty);
    mutex_unlock(&fifo->mutex);
}

// Remove um carro do FIFO
int pfifo_pop(pfifo_t* fifo) {

    mutex_lock(&fifo->mutex);
    while(pfifo_is_empty(fifo)){
        cond_wait(&fifo->notEmpty, &fifo->mutex);
    }
    if (fifo->size > 0) {
        int car_id = fifo->buffer[fifo->front];
        fifo->front = (fifo->front + 1) % fifo->capacity;
        fifo->size--;
        return car_id;
    }
    cond_broadcast(&fifo->notFull);
    mutex_unlock(&fifo->mutex);
    return -1; // Retorna -1 se a fila estiver vazia
}

// Verifica se o FIFO está vazio
int pfifo_is_empty(pfifo_t* fifo) {
    return fifo->size == 0;
}

// Verifica se o FIFO está cheio
int pfifo_is_full(pfifo_t* fifo) {
    return fifo->size == fifo->capacity;
}

