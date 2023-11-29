/*
 *  \author ...
 */

#include "somm23.h"

#include <stdio.h>
#include <stdint.h>

namespace group 
{

// ================================================================================== //

    void pctPrint(FILE *fout)
    {
        soProbe(303, "%s(\"%p\")\n", __func__, fout);

        require(fout != NULL and fileno(fout) != -1, "fout must be a valid file stream");

        // Function to print a line of dashes
        auto printSeparatorLine = [&]() {
            fprintf(fout, "+");
            for (int i = 0; i < 148; ++i) {
                fprintf(fout, "=");
            }
            fprintf(fout, "+\n");
        };
        
        //Print Header
        printSeparatorLine(); 
        fprintf(fout, "|%*sProcess Control Table%*s|\n", 66, "", 61, "");
        fprintf(fout, "+-------+-----------+---------+----------+---------+---------+---------------------------------------+-----------------------------------------------+\n");
        fprintf(fout, "|%*sPID%*s|%*sstate%*s|%*sarrival%*s|%*slifetime%*s|%*sactive%*s|%*sfinish%*s|%*saddress space profile%*s|%*saddress space mapping%*s|\n",
                2,"",2,"",3,"",3,"",1,"",1,"",1,"",1,"",1,"",2,"",1,"",2,"",9,"",9,"",13,"",13,"");
        fprintf(fout, "+-------+-----------+---------+----------+---------+---------+---------------------------------------+-----------------------------------------------+\n");

        // Print process information
        struct PctNode* current = pctHead;
        while (current != nullptr) {
            fprintf(fout, "| %-*u | %-*s | %-*u | %-*u | %-*u | %-*u | %-*u | %-*u |\n",
                5, current->pcb.pid,
                9, current->pcb.state,
                7, current->pcb.arrivalTime,
                8, current->pcb.lifetime,
                6, current->pcb.activationTime,
                7, current->pcb.finishTime,
                37, current->pcb.memProfile,
                46, current->pcb.memMapping);
                
            current = current->next;
        }
        printSeparatorLine();
        fprintf(fout, "\n");
    }

// ================================================================================== //

} // end of namespace group

