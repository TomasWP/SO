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

        printf("+===============================================+\n");
        printf("|             Swapped Process Queue             |\n");
        printf("+-------+---------------------------------------+\n");
        printf("|  PID  |         address space profile         |\n");
        printf("+-------+---------------------------------------+\n");

        SwpNode *current = swpHead;  
        while (current != NULL) {
            fprintf(fout, "| %5u | %17p                     |\n",
                    current->process.pid,
                    (void*)&current->process.profile  
                );

            current = current->next;
        }
        printf("+===============================================+\n");
        printf("\n");

    } catch (const Exception& e) {
        
        throw e;
    }
}

// ================================================================================== //

}  // end of namespace group
