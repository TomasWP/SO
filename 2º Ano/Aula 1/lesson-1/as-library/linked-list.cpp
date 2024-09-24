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
    return list;

    
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
    return false;
}

/*******************************************************/

SllNode* sllRemove(SllNode* list, uint32_t nmec)
{
    assert(list != NULL);
    assert(sllExists(list, nmec));

    return list;
}

/*******************************************************/

const char *sllGetName(SllNode* list, uint32_t nmec)
{
    assert(list != NULL);
    assert(sllExists(list, nmec));

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

    if (ok != NULL)
       *ok = false; // load failure

    return NULL;
}

/*******************************************************/

