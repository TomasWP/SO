/*
 *  BEATRIZ FERREIRA 107214
 */

#include "somm23.h"

#include <stdio.h>
#include <stdint.h>

namespace group {

// ================================================================================== //

void swpPrint(FILE *fout) 
{
    soProbe(403, "%s(\"%p\")\n", __func__, fout);


    /* TODO POINT: Replace next instruction with your code */
    try {
        require(fout != NULL && fileno(fout) != -1, "fout must be a valid file stream");

        fprintf(fout, "+===============================================+\n");
        fprintf(fout, "|             Swapped Process Queue             |\n");
        fprintf(fout, "+-------+---------------------------------------+\n");
        fprintf(fout, "|  PID  |         address space profile         |\n");
        fprintf(fout, "+-------+---------------------------------------+\n");

        SwpNode* temp = swpHead;
        while (temp != NULL) {
            fprintf(fout, "| %5u |", temp->process.pid);
            for (uint32_t i = 0; i < temp->process.profile.segmentCount; i++) {
                fprintf(fout, " %7u :", temp->process.profile.size[i]);
            }
            for (uint32_t i = temp->process.profile.segmentCount; i < MAX_BLOCKS - 1; i++) {
                fprintf(fout, "   ---   :");
            }
            if (temp->process.profile.segmentCount < MAX_BLOCKS) {
                fprintf(fout, "   ---   |"); // End the line with a "|"
            } else {
                fprintf(fout, " %7u |", temp->process.profile.size[MAX_BLOCKS - 1]);
            }
            fprintf(fout, "\n");
            temp = temp->next;
        }

        fprintf(fout, "+===============================================+\n");
        fprintf(fout,"\n");

    } catch (const Exception& e) {
        
        throw e;
    }
}

// ================================================================================== //

} // end of namespace group
