/*
 *  \author Afonso Baixo 108237
 */

#include "somm23.h"

#include <stdio.h>
#include <stdint.h>

namespace group 
{

// ================================================================================== //

    void feqPrint(FILE *fout)
    {
        soProbe(203, "%s(\"%p\")\n", __func__, fout);

        require(fout != NULL and fileno(fout) != -1, "fout must be a valid file stream");

        /* TODO POINT: Replace next instruction with your code */

        // Function to print a line of dashes
        auto printSeparatorLine = [&]() {
            fprintf(fout, "+");
            for (int i = 0; i < 30; ++i) {
                fprintf(fout, "=");
            }
            fprintf(fout, "+\n");
        };
        
        //Print Header
        printSeparatorLine(); 
        fprintf(fout, "|%*sFuture Event Queue%*s|\n", 6, "", 6, "");
        fprintf(fout, "+----------+-----------+-------+\n");
        fprintf(fout, "|%*stime%*s|%*stype%*s|%*sPID%*s|\n",
                3,"",3,"",3,"",4,"",2,"",2,"");
        fprintf(fout, "+----------+-----------+-------+\n");

        // Print process information
        struct FeqEventNode* current = feqHead; 
        while (current != NULL) {
            const char *eventType = current->event.type == ARRIVAL ? "ARRIVAL" : current->event.type == TERMINATE ? "TERMINATE" : "UNKNOWN";
            fprintf(fout, "| %*u | %-*s | %*u |\n",
                8, current->event.time,
                9, eventType,
                5, current->event.pid
                );
                
            current = current->next;
        }
        printSeparatorLine();
        fprintf(fout, "\n");
    }

// ================================================================================== //

} // end of namespace group

