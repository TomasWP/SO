/*
 *  \author Paulo Macedo
 */

#include "sim.h"
#include "somm23.h"

#include <cstdlib>
#include <stdint.h>

namespace group 
{

// ================================================================================== //

    static Address getAddress(uint32_t pid, MemTreeNode* memTreeRoot, uint32_t block_size);

    Address memBuddySystemAlloc(uint32_t pid, uint32_t size)
    {
        soProbe(506, "%s(%u, %#x)\n", __func__, pid, size);

        require(pid > 0, "a valid process ID must be greater than zero");
        require(size, "the size of a memory segment must be greater then zero");
 
        if (memTreeRoot == NULL)
            throw Exception(EINVAL, __func__);
        return getAddress(pid, memTreeRoot, size);
    }

    Address getAddress(uint32_t pid, MemTreeNode* currentNode, uint32_t block_size)
    {
        if (currentNode == NULL || currentNode->block.size < memParameters.chunkSize)
            return NULL_ADDRESS;

        if (currentNode->state == FREE && currentNode->block.size >= block_size * 2) {
            MemTreeNode* leftChild = (MemTreeNode*)malloc(sizeof(MemTreeNode));
            MemTreeNode* rightChild = (MemTreeNode*)malloc(sizeof(MemTreeNode));

            if (leftChild && rightChild) {
                leftChild->state= FREE;
                leftChild->block.size = currentNode->block.size / 2;
                leftChild->block.address = currentNode->block.address;
                leftChild->left = NULL;
                leftChild->right = NULL;

                rightChild->state = FREE;
                rightChild->block.size = currentNode->block.size / 2;
                rightChild->block.address = currentNode->block.address + currentNode->block.size / 2;
                rightChild->left = NULL;
                rightChild->right = NULL;

                currentNode->state = SPLITTED;
                currentNode->left = leftChild;
                currentNode->right = rightChild;
            } else {
                throw Exception(ENOMEM, __func__);
            }
        }
        
        if (currentNode->state == FREE && currentNode->block.size >= block_size) {
            currentNode->state = OCCUPIED;
            currentNode->block.pid = pid;
            return currentNode->block.address;
        }

        Address leftNodeAddress = getAddress(pid, currentNode->left, block_size);
        if (leftNodeAddress != NULL_ADDRESS)
            return leftNodeAddress;

        Address rightAddr = getAddress(pid, currentNode->right, block_size);
        if (rightAddr != NULL_ADDRESS)
            return rightAddr;

        return NULL_ADDRESS;
    }

// ================================================================================== //

} // end of namespace group
