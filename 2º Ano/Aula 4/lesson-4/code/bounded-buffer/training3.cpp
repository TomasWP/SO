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

#define N 5

int buffers_pool[N];
int freeBuffers[N];          // Fifo Buffers livres
int pendingRequests[N];      // FIfo Buffers com pedidos pendentes

// Variáveis de controle
int free_count = N;        // Número de buffers livres
int pending_count = 0;     // Número de pedidos pendentes
int free_index = 0;        // Índice para o próximo buffer livre
int pending_index = 0;     // Índice para o próximo pedido pendente

pthread_mutex_t mutex;
pthread_cond_t free_cond;       // Clientes esperam por buffers livres
pthread_cond_t pending_cond;    // Servidor espera por pedidos pendentes
pthread_cond_t response_cond;   // Clientes esperam por respostas do servidor

int getFreeBuffer(){

    mutex_lock(&mutex);

    while(free_count == 0){

        cond_wait(&free_cond, &mutex);
    }

    int id = freeBuffers[--free_count];

    mutex_unlock(&mutex);

    return id;
}

void putRequestData(int data, int id){

    buffers_pool[id] = data;
}

void submitRequest(int id){

    mutex_lock(&mutex);

    pendingRequests[pending_count++] = id;      // Adiciona o pedido à fila de pendentes
    pthread_cond_signal(&pending_cond);         // Notifica o servidor
    
    mutex_unlock(&mutex);
}

void waitForResponse( int id){

    mutex_lock(&mutex);

    pthread_cond_wait(&response_cond, &mutex);

    mutex_unlock(&mutex);
}

int getResponseData(int id){

    return buffers_pool[id];
}

int getPendingRequest(){

    mutex_lock(&mutex);

    while(pending_count == 0){

        cond_wait(&pending_cond, &mutex);
    }

    int resp = pendingRequests[pending_count--];

    mutex_unlock(&mutex);

    return resp;

}

void releaseBuffer(int id){

    mutex_lock(&mutex);           

    freeBuffers[free_count++] = id;       // Libera o buffer
    pthread_cond_signal(&free_cond);    // Notifica que um buffer foi liberado

    mutex_unlock(&mutex);
}

void *client(void *arg){

    int data = *((int *)arg);  // Dados a enviar

    int id = getFreeBuffer (); /* take a buffer id out of fifo of free buffers */
    putRequestData ( data , id ); /* put request data on buffer */
    submitRequest ( id ); /* add buffer id to fifo of pending requests */
    waitForResponse ( id ); /* wait (blocked) until the response is available */
    int resp = getResponseData ( id ); /* take response out of buffer */
    releaseBuffer ( id ); /* buffer is free, so add its id to fifo of free buffers */
}

void *server(void *arg){

    id = getPendingRequest (); /* take a buffer id out of fifo of pending requests */
    req = getRequestData ( id ); /* take the request */
    resp = produceResponse ( req ); /* produce a response */
    putResponseData ( resp , id ); /* put response data on buffer */
    notifyClient ( id ); /* so client is waked up */
}

int main(void)
{
    pthread_t server_threat;
    pthread_t clients[3];   /* 3 clientes*/

    mutex_init(&mutex, NULL);
    cond_init(&free_cond, NULL);
    cond_init(&pending_cond, NULL);
    cond_init(&free_index, NULL);

    for(int i = 0; i < N; i++){

        freeBuffers[i] = i;
    }

    pthread_create(&server_threat, NULL, server, NULL);
    
    int data[3] = {1, 2, 3};  // Exemplo de dados

    pthread_create(&clients[1], NULL, client, &data[1]);
    pthread_create(&clients[2], NULL, client, &data[2]);
    pthread_create(&clients[3], NULL, client, &data[3]);

    pthread_join(clients[1], NULL);
    pthread_join(clients[2], NULL);
    pthread_join(clients[3], NULL);

    pthread_join(server_threat, NULL);

    return 0;
}