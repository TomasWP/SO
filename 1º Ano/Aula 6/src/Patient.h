#ifndef PATIENT_H
#define PATIENT_H

typedef struct {
    int id;         // ID do paciente
    int priority;   // Prioridade do paciente
    // Adicione outros campos conforme necessário
} Patient;

void* patient_behavior(void* arg) {
    Patient* patient = (Patient*)arg;
    // Simule o comportamento do paciente aqui
    // Por exemplo, você pode inserir o paciente na fila prioritária
    insert_pfifo(&pfifo, patient->id, patient->priority);
    return NULL;
}

#endif