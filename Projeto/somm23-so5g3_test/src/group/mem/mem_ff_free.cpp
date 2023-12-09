/*
 *  BEATRIZ FERREIRA 107214
 */

#include "somm23.h"
#include <stdint.h>

namespace group {

// ================================================================================== //

    void memFirstFitFree(Address address) {
        soProbe(508, "%s(%u)\n", __func__, address);

        require(memOccupiedHead != NULL, "Occupied list should contain nodes");

        /* TODO POINT: Replace next instruction with your code */

        MemListNode* currentNode = memOccupiedHead;

        while (currentNode != NULL && currentNode->block.address != address) {
            currentNode = currentNode->next;
        }

        require(currentNode != NULL, "Block with the given address not found");

        currentNode->block.pid = 0;

        if (currentNode->prev != NULL && currentNode->prev->block.pid == 0) {
            currentNode->prev->block.size += currentNode->block.size;
            currentNode->prev->next = currentNode->next;

            if (currentNode == memOccupiedHead) {
                memOccupiedHead = currentNode->next;
            }

            delete currentNode;
            currentNode = currentNode->prev;
        }

        if (currentNode->next != NULL && currentNode->next->block.pid == 0) {
            currentNode->block.size += currentNode->next->block.size;
            MemListNode* toDelete = currentNode->next;
            currentNode->next = currentNode->next->next;
            delete toDelete;
        }

  
        if (memFreeHead == NULL || address < memFreeHead->block.address) {
            currentNode->next = memFreeHead;
            currentNode->prev = NULL;

            if (memFreeHead != NULL) {
                memFreeHead->prev = currentNode;
            }

            memFreeHead = currentNode;
        } else {
            MemListNode* temp = memFreeHead;

            while (temp->next != NULL && temp->next->block.address < address) {
                temp = temp->next;
            }

            currentNode->next = temp->next;
            currentNode->prev = temp;

            if (temp->next != NULL) {
                temp->next->prev = currentNode;
            }

            temp->next = currentNode;
        }
    }

// ================================================================================== //

}  // end of namespace group
