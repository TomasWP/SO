/*
 *  \author: Tomás Sousa Fonseca 107245
 */

#include "somm23.h"

#include <stdint.h>

namespace group 
{

// ================================================================================== //

    void memInit(uint32_t mSize, uint32_t osSize, uint32_t cSize, AllocationPolicy policy) 
    {
        const char *pas = policy == FirstFit ? "FirstFit" : policy == BuddySystem ? "BuddySystem" : "Unkown";
        soProbe(501, "%s(%#x, %#x, %#x, %s)\n", __func__, mSize, osSize, cSize, pas);

        require(mSize > osSize, "memory must be bigger than the one use by OS");
        require((mSize % cSize) == 0, "memory size must be a multiple of chunck size");
        require((osSize % cSize) == 0, "memory size for OS must be a multiple of chunck size");
        require(policy == FirstFit or policy == BuddySystem, "policy must be FirstFit or BuddySystem");

        try{
            memParameters.chunkSize = cSize;
            memParameters.kernelSize= osSize;
            memParameters.policy    = policy;
            memParameters.totalSize = mSize;

            if (policy == FirstFit) 
            {
                // Allocate memory for the new MemBlock
                MemBlock* newBlock = new MemBlock;
                newBlock->pid = 0; // 0 indicates the block is free
                newBlock->size = mSize - osSize;
                newBlock->address = osSize; // The start address of the block is right after the OS

                // Allocate memory for the new MemListNode and set its block field to the new MemBlock
                MemListNode* newNode = new MemListNode;
                newNode->block = *newBlock;
                newNode->prev = NULL;
                newNode->next = NULL;

                // If memFreeHead is NULL, then the list is empty, so set memFreeHead to the new node
                if (memFreeHead == NULL) {
                    memFreeHead = newNode;
                }
                else {
                    // Otherwise, add the new node to the start of the list
                    newNode->next = memFreeHead;
                    memFreeHead->prev = newNode;
                    memFreeHead = newNode;
                }

                // Initialize the head of the occupied list to NULL as no blocks are allocated yet
                memOccupiedHead = NULL;
            }
            else if (policy == BuddySystem) 
            {
                // Set the free and occupied lists to NULL
                memFreeHead = NULL;
                memOccupiedHead = NULL;

                uint32_t total_mem = cSize;
                while (total_mem * 2 <= mSize - osSize) 
                    total_mem <<= 1; 

                // Allocate memory for the new MemBlock
                MemBlock* newBlock = new MemBlock;
                newBlock->pid = 0; // 0 indicates the block is free
                newBlock->size = total_mem;
                newBlock->address = osSize; // The start address of the block is right after the OS

                // Allocate memory for the new MemTreeNode and set its block field to the new MemBlock
                MemTreeNode* newNode = new MemTreeNode;
                newNode->block = *newBlock;
                newNode->left = NULL;
                newNode->right = NULL;
                newNode->state = FREE;

                memTreeRoot = newNode;

            }
        } catch (const Exception& e) {
            throw e;
        }

    }

// ================================================================================== //

} // end of namespace group

