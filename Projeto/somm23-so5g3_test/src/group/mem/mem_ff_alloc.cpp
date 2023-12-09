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
        MemListNode* currentNode = memFreeHead;
        while (currentNode != NULL) {
            if (currentNode->block.size >= size) {
                currentNode->block.pid = pid;

                if (currentNode->block.size > size) {
                    MemListNode* newFreeBlock = new MemListNode();
                    newFreeBlock->block.pid = 0;
                    newFreeBlock->block.size = currentNode->block.size - size;
                    newFreeBlock->block.address = currentNode->block.address + size;

                    newFreeBlock->next = currentNode->next;
                    newFreeBlock->prev = currentNode;
                    currentNode->next = newFreeBlock;

                    if (newFreeBlock->next != NULL) {
                        newFreeBlock->next->prev = newFreeBlock;
                    }
                }

                return currentNode->block.address;
            }

            currentNode = currentNode->next;
        }

        throw Exception(ENOMEM, __func__);
    }

// ================================================================================== //

}  // end of namespace group

