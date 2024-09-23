/*
 *  BEATRIZ FERREIRA 107214
 */

#include "somm23.h"

#include <stdio.h>
#include <stdint.h>

namespace group
{

    // ================================================================================== //

    void swpPrint(FILE *fout)
    {
        soProbe(403, "%s(\"%p\")\n", __func__, fout);

        /* TODO POINT: Replace next instruction with your code */
        try
        {
            require(fout != NULL && fileno(fout) != -1, "fout must be a valid file stream");

            fprintf(fout, "+===============================================+\n");
            fprintf(fout, "|             Swapped Process Queue             |\n");
            fprintf(fout, "+-------+---------------------------------------+\n");
            fprintf(fout, "|  PID  |         address space profile         |\n");
            fprintf(fout, "+-------+---------------------------------------+\n");

            SwpNode *temp = swpHead;
            while (temp != NULL)
            {

                fprintf(fout, "| %5u |", temp->process.pid);

                uint32_t i;
                for (i = 0; i < temp->process.profile.segmentCount; i++)
                {
                    uint32_t size = temp->process.profile.size[i];

                    if (i == MAX_SEGMENTS - 1)
                    {
                        fprintf(fout, " %*u |", 7, size);
                        break;
                    }

                    fprintf(fout, " %7u :", size);
                }

                uint32_t j;
                for (j = 0; j < (MAX_BLOCKS - temp->process.profile.segmentCount); j++)
                {
                    if ((MAX_BLOCKS - temp->process.profile.segmentCount) == 1 || j == ((MAX_BLOCKS - temp->process.profile.segmentCount) - 1))
                    {
                        fprintf(fout, "   ---   |");
                        break;
                    }

                    fprintf(fout, "   ---   :");
                }

                fprintf(fout, "\n");
                temp = temp->next;
            }

            fprintf(fout, "+===============================================+\n");
            fprintf(fout, "\n");
        }
        catch (const Exception &e)
        {

            throw e;
        }
    }

    // ================================================================================== //

} // end of namespace group
