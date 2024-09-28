#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#include "linked-list.h"

/*******************************************************/

SllNode* sllDestroy(SllNode* list)
{
    SllNode* current = list;
    SllNode* nextnode = NULL;

    while(current != NULL){

        nextnode = current->next;
        free(current);
        current = nextnode;
    }
    
    return NULL;
}

/*******************************************************/

void sllPrint(SllNode *list, FILE *fout)
{
    if(!list){
        fprintf(fout,"Lista Vazia!\n");
        return;
    }else{
        SllNode* current = list;
        while(current != NULL){
            fprintf(fout,"Nmec: %u, Nome: %s\n", current->reg.nmec, current->reg.name);
            current = current->next;
        }
    }
}

/*******************************************************/

SllNode* sllInsert(SllNode* list, uint32_t nmec, const char *name)
{
    assert(name != NULL && name[0] != '\0'); // Pré-condição do nome
    assert(!sllExists(list, nmec)); // Pré-condição de que o nmec não deve existir

    // Criar um novo nó
    SllNode* newNode = (SllNode*)malloc(sizeof(SllNode));
    if (!newNode) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }

    // Duplicar o nome dinamicamente
    newNode->reg.name = strdup(name);
    if (!newNode->reg.name) {
        perror("Failed to allocate memory for name");
        free(newNode); // Liberar o nó caso a alocação falhe
        exit(EXIT_FAILURE);
    }
    
    newNode->reg.nmec = nmec;
    newNode->next = NULL;

        // Inserir na posição correta para manter a ordem
    if (list == NULL || list->reg.nmec > nmec) {
        // Inserir no início da lista
        newNode->next = list;
        return newNode; // Novo cabeçalho
    }

    // Percorrer a lista para encontrar a posição correta
    SllNode* current = list;
    while (current->next != NULL && current->next->reg.nmec < nmec) {
        current = current->next;
    }

    // Inserir o novo nó na posição correta
    newNode->next = current->next;
    current->next = newNode;

    return list; // Retornar o cabeçalho da lista
}

/*******************************************************/

bool sllExists(SllNode* list, uint32_t nmec)
{
    SllNode* current = list;
    while(current != NULL && nmec >= current->reg.nmec){
        if(current->reg.nmec == nmec){

            return true;
        }
        current = current->next;
    }
    return false;
}

/*******************************************************/

SllNode* sllRemove(SllNode* list, uint32_t nmec)
{
    if(list == NULL){
        printf("Erro: a lista está vazia.\n");
        return NULL;
    }

    if(!sllExists(list, nmec)){
        printf("Erro: nmec %u não encontrado na lista.\n", nmec);
        return NULL;
    }

    SllNode* current = list;
    SllNode* previous = NULL;
    
    while (current != NULL && current->reg.nmec < nmec) {
        previous = current;      // Armazena o nó anterior
        current = current->next; // Avança para o próximo nó
    }

    // Se chegamos aqui, current pode ser NULL ou o nó a ser removido
    // Verifica se o nmec é igual ao que queremos remover
    if (current != NULL && current->reg.nmec == nmec) {
        // Se o nó a ser removido é o primeiro nó
        if (previous == NULL) {
            // Remove o nó da cabeça da lista
            list = current->next; // Atualiza a cabeça da lista
        } else {
            previous->next = current->next; // Conecta o anterior ao próximo do nó atual
        }

        // Libera a memória do nó removido
        free(current);
    }

    return list;
}

/*******************************************************/

const char *sllGetName(SllNode* list, uint32_t nmec)
{
    if (list == NULL) {
        printf("Erro: a lista está vazia.\n");
        return NULL;
    }

    if (!sllExists(list, nmec)) {
        printf("Erro: nmec %u não encontrado na lista.\n", nmec);
        return NULL;
    }

    SllNode* current = list;
    printf("Procurando nmec: %u\n", nmec);
    
    while (current != NULL) {
        if (current->reg.nmec == nmec) {
            return current->reg.name; // Retorna o nome se encontrar o nmec
        }
        
        // Como a lista está ordenada, se o nmec atual for maior, não precisamos continuar
        if (current->reg.nmec > nmec) {
            break;
        }
        
        current = current->next; // Avança para o próximo nó
    }
    
    // Não deve alcançar esta linha se sllExists estiver correto
    return NULL; // Para evitar warnings; pode ser removido
}

/*******************************************************/

SllNode* sllLoad(SllNode *list, FILE *fin, bool *ok)
{
    assert(fin != NULL);

    if (ok != NULL){
       *ok = false; // load failure
    }else{
        *ok = true; // load success
        char nome[100];
        int numero;

        // Ler o ficheiro linha por linha
        while (fscanf(fin, " %[^\;];%d", nome, &numero) == 2) {
            // Inserir na lista
            list = sllInsert(list, numero, nome);
        }

        // Fechar o ficheiro
        fclose(fin);
        return list;
    }
    return NULL;
}

/*******************************************************/

