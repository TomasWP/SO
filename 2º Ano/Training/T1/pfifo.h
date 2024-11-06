#ifndef PFIFO_H
#define PFIFO_H

#include <stdint.h>
#include  "settings.h"
#include "thread.cpp"

// Estrutura para o FIFO (First In First Out)
typedef struct {
    int* buffer;         // Buffer para armazenar os IDs dos carros
    int capacity;        // Capacidade máxima do FIFO
    int size;            // Tamanho atual da fila
    int front;           // Índice da frente da fila
    int rear;            // Índice da parte de trás da fila
    pthread_mutex_t mutex;
    pthread_cond_t notEmpty, notFull;
} pfifo_t;

// Funções para gerenciar o FIFO
void pfifo_init(pfifo_t* fifo, int capacity);
void pfifo_free(pfifo_t* fifo);
void pfifo_push(pfifo_t* fifo, int car_id);
int pfifo_pop(pfifo_t* fifo);
int pfifo_is_empty(pfifo_t* fifo);
int pfifo_is_full(pfifo_t* fifo);

#endif

