/*
 *  BEATRIZ FERREIRA 107214
 */

#include "somm23.h"

#include <stdint.h>

namespace group 
{

// ================================================================================== //

    Address memFirstFitAlloc(uint32_t pid, uint32_t size)
    {
        soProbe(505, "%s(%u, %#x)\n", __func__, pid, size);

        require(pid > 0, "a valid process ID must be greater than zero");
        require(size, "the size of a memory segment must be greater then zero");

        /* TODO POINT: Replace next instruction with your code */
        MemListNode* freeBlock = memFreeHead;
        MemListNode* prevFreeBlock = NULL;
        while (freeBlock != NULL && freeBlock->block.size < size) {
            prevFreeBlock = freeBlock;
            freeBlock = freeBlock->next;
        }

        if (freeBlock == NULL) {
            return NULL_ADDRESS;
        }

        if (freeBlock->block.size > size) {
            MemListNode* newFreeBlock = new MemListNode;
            newFreeBlock->block.pid = 0;
            newFreeBlock->block.size = freeBlock->block.size - size;
            newFreeBlock->block.address = freeBlock->block.address + size;
            newFreeBlock->next = freeBlock->next;
            newFreeBlock->prev = freeBlock;
            if (freeBlock->next != NULL) {
                freeBlock->next->prev = newFreeBlock;
            }
            freeBlock->next = newFreeBlock;
            freeBlock->block.size = size;
        }

        if (prevFreeBlock != NULL) {
            prevFreeBlock->next = freeBlock->next;
        } else {
            memFreeHead = freeBlock->next;
        }
        if (freeBlock->next != NULL) {
            freeBlock->next->prev = prevFreeBlock;
        }

        MemListNode* currentOccupied = memOccupiedHead;
        MemListNode* prevOccupied = NULL;
        while (currentOccupied != NULL && currentOccupied->block.address < freeBlock->block.address) {
            prevOccupied = currentOccupied;
            currentOccupied = currentOccupied->next;
        }

        freeBlock->next = currentOccupied;
        freeBlock->prev = prevOccupied;

        if (prevOccupied != NULL) {
            prevOccupied->next = freeBlock;
        } else {
            memOccupiedHead = freeBlock;
        }

        if (currentOccupied != NULL) {
            currentOccupied->prev = freeBlock;
        }

        freeBlock->block.pid = pid;
        return freeBlock->block.address;
    }

// ================================================================================== //

}  // end of namespace group