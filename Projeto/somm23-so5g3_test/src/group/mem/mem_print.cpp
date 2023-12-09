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
    void printBlock(FILE *fout, const MemBlock &block, bool isFreeBlock) {
        if (isFreeBlock) {
            fprintf(fout, "|   ---   |     0x%05x |     %6u |\n", block.address, block.size);
        } else {
            fprintf(fout, "|    %4u |     0x%05x |     %6u |\n", block.pid, block.address, block.size);
        }
    } 

    void memPrint(FILE *fout) {
        soProbe(503, "%s(\"%p\")\n", __func__, fout);

        if (fout == NULL || fileno(fout) == -1) {
            throw Exception(ENOSYS, __func__);
        }

        // Print header for occupied blocks
        fprintf(fout, "+====================================+\n");
        fprintf(fout, "|   FirstFit memory occupied blocks  |\n");
        fprintf(fout, "+---------+-------------+------------+\n");
        fprintf(fout, "|   PID   |   address   |    size    |\n");
        fprintf(fout, "+---------+-------------+------------+\n");

        // Print occupied blocks
        MemListNode *current = memOccupiedHead;
        while (current != NULL) {
            printBlock(fout, current->block, false);
            current = current->next;
        }
        fprintf(fout, "+====================================+\n\n");

        // Print header for free blocks
        fprintf(fout, "+====================================+\n");
        fprintf(fout, "|     FirstFit memory free blocks    |\n");
        fprintf(fout, "+---------+-------------+------------+\n");
        fprintf(fout, "|   PID   |   address   |    size    |\n");
        fprintf(fout, "+---------+-------------+------------+\n");

        // Print free blocks
        current = memFreeHead;
        while (current != NULL) {
            printBlock(fout, current->block, true);
            current = current->next;
        }
        fprintf(fout, "+====================================+\n\n");
    }

// ================================================================================== //

} // end of namespace group

