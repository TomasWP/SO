/*
 *  \author Diogo Borges - 102954
 */

#include "somm23.h"

#include <stdio.h>
#include <stdint.h>

namespace group 
{
    
// ================================================================================== //
    // Helper function to print a memory block
    void printBlock(FILE *fout, const MemBlock &block, MemTreeNodeType isFreeBlock) {
        if (isFreeBlock == FREE) {
            fprintf(fout, "|   ---   |    %#8x |   %8u |\n", block.address, block.size);
        } else if (isFreeBlock == OCCUPIED){
            fprintf(fout, "|    %4u |    %#8x |   %8u |\n", block.pid, block.address, block.size);
        }
    } 
    
    void FFheaderOccupBlocks(FILE *fout){
        fprintf(fout, "+====================================+\n");
        fprintf(fout, "|   FirstFit memory occupied blocks  |\n");
        fprintf(fout, "+---------+-------------+------------+\n");
        fprintf(fout, "|   PID   |   address   |    size    |\n");
        fprintf(fout, "+---------+-------------+------------+\n");
    }

    void FFheaderFreeBlocks(FILE *fout){
        fprintf(fout, "+====================================+\n");
        fprintf(fout, "|     FirstFit memory free blocks    |\n");
        fprintf(fout, "+---------+-------------+------------+\n");
        fprintf(fout, "|   PID   |   address   |    size    |\n");
        fprintf(fout, "+---------+-------------+------------+\n");
    }

    void BSheaderOccupBlocks(FILE *fout){
        fprintf(fout, "+====================================+\n");
        fprintf(fout, "|   BuddySystem memory free blocks   |\n");
        fprintf(fout, "+---------+-------------+------------+\n");
        fprintf(fout, "|   PID   |   address   |    size    |\n");
        fprintf(fout, "+---------+-------------+------------+\n");
    }

    void BSheaderFreeBlocks(FILE *fout){
        fprintf(fout, "+====================================+\n");
        fprintf(fout, "| BuddySystem memory occupied blocks |\n");
        fprintf(fout, "+---------+-------------+------------+\n");
        fprintf(fout, "|   PID   |   address   |    size    |\n");
        fprintf(fout, "+---------+-------------+------------+\n");
    }

    void traverseBuddySystem(FILE *fout, MemTreeNode *node, MemTreeNodeType desiredState) {
        if (node == NULL) return;
        if (node->state != desiredState) {
            printBlock(fout, node->block, node->state);
        }
        traverseBuddySystem(fout, node->left, desiredState);
        traverseBuddySystem(fout, node->right, desiredState);
    }

    void memPrint(FILE *fout) {
        soProbe(503, "%s(\"%p\")\n", __func__, fout);

        if (fout == NULL || fileno(fout) == -1) {
            throw Exception(ENOSYS, __func__);
        }

        AllocationPolicy currentPolicy = memParameters.policy;
        MemListNode *current = memOccupiedHead;

        if(currentPolicy == FirstFit){
            FFheaderOccupBlocks(fout);
            while (current != NULL) {
                printBlock(fout, current->block, OCCUPIED);
                current = current->next;
            }
        }else{
            BSheaderFreeBlocks(fout);
            traverseBuddySystem(fout, memTreeRoot, FREE);
        }

        fprintf(fout, "+====================================+\n\n");

        if(currentPolicy == FirstFit){
            FFheaderFreeBlocks(fout);
            current = memFreeHead;
            while (current != NULL) {
                printBlock(fout, current->block, FREE);
                current = current->next;
            }
        }else{
            BSheaderOccupBlocks(fout);
            traverseBuddySystem(fout, memTreeRoot, OCCUPIED);
        }

        fprintf(fout, "+====================================+\n\n");
    }

// ================================================================================== //

} // end of namespace group

