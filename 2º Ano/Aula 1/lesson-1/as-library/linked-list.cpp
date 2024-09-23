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
            fprintf(fout,"Nmec: %u, Nome: %s", current->reg.nmec, current->reg.name);
            current = current->next;
        }
    }
}

/*******************************************************/

SllNode* sllInsert(SllNode* list, uint32_t nmec, const char *name)
{
    assert(name != NULL && name[0] != '\0');
    assert(!sllExists(list, nmec));

    SllNode* newnode = (SllNode*)malloc(sizeof(SllNode));   // alocar memória para um novo nó usando malloc

    newnode->reg.nmec = nmec;
    newnode->reg.name = strdup(name);
    newnode->next = NULL;

    if(list == NULL || newnode->reg.nmec > nmec){
        newnode->next = list;
        return newnode;
    }

    SllNode* current = list;
    while(current->next != NULL && current->next->reg.nmec < nmec){
        current = current->next;
    }

    current->next = newnode;
    newnode->next = current->next;

    return list;
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

    return NULL;
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

