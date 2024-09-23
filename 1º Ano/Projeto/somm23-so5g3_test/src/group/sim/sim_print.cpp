/*
 *  \author Luis Leal
 */

#include "somm23.h"

#include <stdio.h>
#include <stdint.h>

namespace group
{

    // ================================================================================== //

    void simPrint(FILE *fout)
    {
        soProbe(103, "%s(\"%p\")\n", __func__, fout);

        require(fout != NULL and fileno(fout) != -1, "fout must be a valid file stream");

        /* TODO POINT: Replace next instruction with your code */
        // throw Exception(ENOSYS, __func__);

        fprintf(fout, "+====================================================================+\n");
        fprintf(fout, "|%*sforthcomingTable%*s|\n", 26, "", 26, "");
        fprintf(fout, "+-------+---------+----------+---------------------------------------+\n");
        fprintf(fout, "|%*sSimulation step: %*u |%*sSimulation time: %*u |\n", 4, "", 6, stepCount, 14, "", 7, simTime);
        fprintf(fout, "+-------+---------+----------+---------------------------------------+\n");
        fprintf(fout, "|  PID  | arrival | lifetime |%*saddress space profile%*s|\n", 9, "", 9, "");
        fprintf(fout, "+-------+---------+----------+---------------------------------------+\n");

        uint32_t i;
        uint32_t count = forthcomingTable.count;
        for (i = 0; i < count; i++)
        {
            uint32_t pid = forthcomingTable.process[i].pid;
            uint32_t arrival = forthcomingTable.process[i].arrivalTime;
            uint32_t lifetime = forthcomingTable.process[i].lifetime;
            uint32_t segmentCount = forthcomingTable.process[i].addressSpace.segmentCount;

            fprintf(fout, "| %*u | %*u | %*u |", 5, pid, 7, arrival, 8, lifetime);

            uint32_t j;
            for (j = 0; j < segmentCount; j++)
            {
                uint32_t size = forthcomingTable.process[i].addressSpace.size[j];

                if (j == MAX_SEGMENTS - 1)
                {
                    fprintf(fout, " %*u |", 7, size);
                    break;
                }

                fprintf(fout, " %*u :", 7, size);
            }

            uint32_t k;
            for (k = 0; k < (MAX_BLOCKS - segmentCount); k++)
            {
                if ((MAX_BLOCKS - segmentCount) == 1 || k == ((MAX_BLOCKS - segmentCount) - 1))
                {
                    fprintf(fout, "   ---   |");
                    break;
                }

                fprintf(fout, "   ---   :");
            }

            fprintf(fout, "\n");
        }

        fprintf(fout, "+====================================================================+\n");
        fprintf(fout, "\n");
    }

    // ================================================================================== //

} // end of namespace group
