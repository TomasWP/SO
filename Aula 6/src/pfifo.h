/*
 * @brief A priority FIFO (implemented with a circular array),
 *        whose elements are pairs of integers, one being an
 *        non-negative id and the other a positive priority value.
 * 
 * The following operations are defined:
 *    \li initializer
 *    \li check if is empty
 *    \li check if is full
 *    \li insertion of a value with a given priority
 *    \li retrieval of a value.
 **/


#ifndef PFIFO_H
#define PFIFO_H

#include <stdint.h>
#include  "settings.h"

// TODO point: uncomment the desired implementation
//#include "thread.h"
//#include "process.h"
typedef struct
{
   struct
   {
      int id;         // element ID (works as an index in array all_patients)
      int priority;   // patient priority in FIFO
   } array[FIFO_MAXSIZE];
   int inp;  ///< point of insertion (queue tail)
   int out;  ///< point of retrieval (queue head)
   int cnt;  ///< number of items stored
   pthread_mutex_t lock;  // Mutex for synchronization
} PriorityFIFO;

void init_pfifo(PriorityFIFO* pfifo) {
    pfifo->inp = 0;
    pfifo->out = 0;
    pfifo->cnt = 0;
    pthread_mutex_init(&pfifo->lock, NULL);
}

void term_pfifo(PriorityFIFO* pfifo) {
    // Não há necessidade de limpar a memória da fila, pois ela é estática
    pthread_mutex_destroy(&pfifo->lock);
}

void insert_pfifo(PriorityFIFO* pfifo, int id, int priority) {
    pthread_mutex_lock(&pfifo->lock);
    // Verifique se a fila não está cheia
    if (pfifo->cnt != FIFO_MAXSIZE) {
        pfifo->array[pfifo->inp].id = id;
        pfifo->array[pfifo->inp].priority = priority;
        pfifo->inp = (pfifo->inp + 1) % FIFO_MAXSIZE;
        pfifo->cnt++;
    }
    pthread_mutex_unlock(&pfifo->lock);
}

int retrieve_pfifo(PriorityFIFO* pfifo) {
    pthread_mutex_lock(&pfifo->lock);
    int id = -1; // Retorne -1 se a fila estiver vazia
    // Verifique se a fila não está vazia
    if (pfifo->cnt != 0) {
        id = pfifo->array[pfifo->out].id;
        pfifo->out = (pfifo->out + 1) % FIFO_MAXSIZE;
        pfifo->cnt--;
    }
    pthread_mutex_unlock(&pfifo->lock);
    return id;
}

#endif
