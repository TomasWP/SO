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

        MemListNode* currentOccupied = memOccupiedHead;
        MemListNode* previousOccupied = NULL;

        while (currentOccupied != NULL && currentOccupied->block.address != address) {
            previousOccupied = currentOccupied;
            currentOccupied = currentOccupied->next;
        }

        if (currentOccupied == NULL) {
            throw Exception(EINVAL, __func__);
        }

        if (previousOccupied != NULL) {
            previousOccupied->next = currentOccupied->next;
        } else {
            memOccupiedHead = currentOccupied->next;
        }

        if(currentOccupied->next != NULL){
            currentOccupied->next->prev = previousOccupied;
        }

        MemListNode* currentFree = memFreeHead;
        MemListNode* previousFree = NULL;

        while (currentFree != NULL && currentFree->block.address < address) {
            previousFree = currentFree;
            currentFree = currentFree->next;
        }

        if (previousFree != NULL && previousFree->block.address + previousFree->block.size == address) {
            previousFree->block.size += currentOccupied->block.size;
        } else {

            currentOccupied->next = currentFree;
            currentOccupied->prev = previousFree;
            if (previousFree != NULL) {
                previousFree->next = currentOccupied;
            } else {
                memFreeHead = currentOccupied;
            }
            previousFree = currentOccupied;
        }

        if (currentFree != NULL && previousFree->block.address + previousFree->block.size == currentFree->block.address) {
            previousFree->block.size += currentFree->block.size;
            previousFree->next = currentFree->next;
            delete currentFree;
        }
    }
// ================================================================================== //

}  // end of namespace group
