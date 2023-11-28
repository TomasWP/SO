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

        auto printSeparatorLine = [&]() {
            fprintf(fout, "+");
            for (int i = 0; i < 35; ++i) {
                fprintf(fout, "=");
            }
            fprintf(fout, "+\n");
        };

        printSeparatorLine();
        fprintf(fout, "|%*sSwapped Process Queue%*s|\n", 10, "", 10, "");
        fprintf(fout, "+-------+---------------------------------------+\n");
        fprintf(fout, "|%*sPID%*s|%*sAddress Space Profile%*s|\n", 8, "", 8, "", 16, "", 7, "");
        fprintf(fout, "+-------+---------------------------------------+\n");

        SwpNode *current = swpHead;  
        while (current != NULL) {
            fprintf(fout, "| %8u | %-16p |\n",
                    current->process.pid,
                    (void*)&current->process.profile  
                );

            current = current->next;
        }
        printSeparatorLine();
        fprintf(fout, "+\n");

    } catch (const Exception& e) {
        
        throw e;
    }
}

// ================================================================================== //

}  // end of namespace group
