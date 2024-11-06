#include <stdio.h>
#include <stdlib.h>
#include "pfifo.h"
#include "thread.cpp"

#define MAX_SPOTS 10  // Número máximo de vagas

// Estrutura para o estacionamento
typedef struct {
    int spots[MAX_SPOTS];  // Vagas: 0 para livre, 1 para ocupada
    pfifo_t waiting_queue; // FIFO para gerenciar carros esperando
    int available_spots;   // Contador de vagas disponíveis
    int is_closed;         // Indicador de fechamento do estacionamento
    pthread_mutex_t parking_mutex;
    pthread_cond_t spot_available;
} ParkingLot;

// Função de inicialização do estacionamento
void init_parking_lot(ParkingLot* parking) {
    for (int i = 0; i < MAX_SPOTS; i++) {
        parking->spots[i] = 0; // Todas as vagas começam livres
    }
    parking->available_spots = MAX_SPOTS;
    parking->is_closed = 0;
    pfifo_init(&parking->waiting_queue, MAX_SPOTS);
    mutex_init(&parking->parking_mutex, NULL);
    cond_wait(&parking->spot_available, NULL);
}

// Função de finalização do estacionamento
void term_parking_lot(ParkingLot* parking) {
    pfifo_free(&parking->waiting_queue);
}

// Função de entrada de carros
void car_entry(ParkingLot* parking, int car_id) {
        
    mutex_lock(&parking->parking_mutex);

    while(parking->available_spots == 0){
        printf("Estacionamento cheio. Carro %d aguardando.\n", car_id);
        pfifo_push(&parking->waiting_queue, car_id); // Adiciona o carro à fila de espera
        cond_wait(&parking->spot_available, &parking->parking_mutex);
    }

    if (parking->is_closed) {
        printf("Estacionamento fechado. Carro %d não pode entrar.\n", car_id);
        mutex_unlock(&parking->parking_mutex);
        return;
    }
        
    // Encontrar uma vaga livre
    for (int i = 0; i < MAX_SPOTS; i++) {
        if (parking->spots[i] == 0) { // Se a vaga estiver livre
            parking->spots[i] = 1; // Ocupa a vaga
            parking->available_spots--; // Atualiza o contador de vagas disponíveis
            printf("Carro %d entrou na vaga %d.\n", car_id, i);
            return;
        }
    }
    mutex_unlock(&parking->parking_mutex);
}

// Função de saída de carros
void car_exit(ParkingLot* parking, int car_id) {

    mutex_lock(&parking->parking_mutex);

    for (int i = 0; i < MAX_SPOTS; i++) {
        if (parking->spots[i] == 1) { // Se a vaga estiver ocupada
            parking->spots[i] = 0; // Libera a vaga
            parking->available_spots++; // Atualiza o contador de vagas disponíveis
            printf("Carro %d saiu da vaga %d.\n", car_id, i);
            cond_broadcast(&parking->spot_available);

            // Verifica se há carros na fila de espera
            if (!pfifo_is_empty(&parking->waiting_queue)) {
                int next_car = pfifo_pop(&parking->waiting_queue);
                car_entry(parking, next_car); // Chama car_entry para o próximo carro na fila
            }
            return;
        }
    }
    printf("Carro %d não estava no estacionamento.\n", car_id);
    mutex_unlock(&parking->parking_mutex);
}

// Função para fechar o estacionamento
void close_parking_lot(ParkingLot* parking) {
    mutex_lock(&parking->parking_mutex);

    parking->is_closed = 1;
    printf("Estacionamento fechado. Todos os carros devem sair.\n");
    // Libera todas as vagas restantes
    for (int i = 0; i < MAX_SPOTS; i++) {
        if (parking->spots[i] == 1) {
            car_exit(parking, i); // Saída simulada do carro (usando o índice como ID)
        }
    }
    cond_broadcast(&parking->spot_available);
    mutex_unlock(&parking->parking_mutex);
}

// Função para simular a entrada de um carro em uma thread
void* car_entry_thread(void* arg) {
    ParkingLot* parking = (ParkingLot*)arg;
    for (int i = 1; i <= 5; i++) {
        car_entry(parking, i);
        sleep(1); // Simula tempo entre entradas
    }
    return NULL;
}

// Função para simular a saída de um carro em uma thread
void* car_exit_thread(void* arg) {
    ParkingLot* parking = (ParkingLot*)arg;
    for (int i = 1; i <= 5; i++) {
        car_exit(parking, i);
        sleep(1); // Simula tempo entre saídas
    }
    return NULL;
}

// Função principal para simular a entrada e saída de carros
int main() {
    ParkingLot parking;
    init_parking_lot(&parking);

    pthread_t entry_thread, exit_thread;
    thread_create(&entry_thread, NULL, car_entry_thread, &parking);
    thread_create(&entry_thread, NULL, car_exit_thread, &parking);


    // Simulação de entrada de carros
    car_entry(&parking, 1);
    car_entry(&parking, 2);
    car_entry(&parking, 3);
    car_entry(&parking, 4);
    car_entry(&parking, 5);
    car_entry(&parking, 6);
    car_entry(&parking, 7);
    car_entry(&parking, 8);
    car_entry(&parking, 9);
    car_entry(&parking, 10);
    car_entry(&parking, 11); // Este carro deve esperar

    // Simulação de saída de carros
    car_exit(&parking, 3);
    car_exit(&parking, 1);
    car_exit(&parking, 2);
    car_exit(&parking, 4);
    car_exit(&parking, 5);
    car_exit(&parking, 6);

    thread_join(entry_thread, NULL);
    thread_join(exit_thread, NULL);
    
    // Fechar estacionamento
    close_parking_lot(&parking);

    term_parking_lot(&parking);
    return 0;
}

