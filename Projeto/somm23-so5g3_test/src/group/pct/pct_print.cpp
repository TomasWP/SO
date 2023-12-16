/*
 *  \author Diogo Borges - 102954, Paulo Macedo
 */

#include "pct.h"
#include "somm23.h"
#include "tme.h"

#include <stdio.h>
#include <stdint.h>

namespace group
{
    static void printSeparatorLine(FILE *f);
    static void printTableLine(FILE *fout, const uint32_t *widths, uint32_t size);
    static void printMemProfile(AddressSpaceProfile *memProfile, FILE *f);
    static void printMemMapping(AddressSpaceMapping *memMapping, FILE *f);
    static void printFinishTime(FILE *fout, PctNode *current);
    static void printActivationTime(FILE *fout, PctNode *current);

    // ================================================================================== //
    void pctPrint(FILE *fout)
    {
        soProbe(303, "%s(\"%p\")\n", __func__, fout);

        require(fout != NULL and fileno(fout) != -1, "fout must be a valid file stream");

        const uint32_t colWidths[] = {5, 9, 7, 8, 7, 7, 37, 45}; // Define column widths
        uint32_t numOfColumns = sizeof(colWidths) / sizeof(colWidths[0]);

        printSeparatorLine(fout);
        fprintf(fout, "|%*sProcess Control Table%*s|\n", 66, "", 61, "");
        printTableLine(fout, colWidths, numOfColumns);
        fprintf(fout, "|  PID  |   state   | arrival | lifetime | active  | finish  |         address space profile         |             address space mapping             |\n");
        printTableLine(fout, colWidths, numOfColumns);

        struct PctNode *current = pctHead;

        while (current != NULL)
        {
            const char *state = pctGetStateAsString(current->pcb.pid);

            fprintf(fout, "| %5u | %-9s | %7u | %8u |",
                    current->pcb.pid,
                    state,
                    current->pcb.arrivalTime,
                    current->pcb.lifetime);

            printActivationTime(fout, current);
            printFinishTime(fout, current);
            printMemProfile(&current->pcb.memProfile, fout);
            printMemMapping(&current->pcb.memMapping, fout);

            current = current->next;
        }
        printSeparatorLine(fout);
        fprintf(fout, "\n");
    }

    static uint32_t i;
    static uint32_t j;

    static void printSeparatorLine(FILE *f)
    {
        fprintf(f, "+");
        for (i = 0; i < 148; ++i)
        {
            fprintf(f, "=");
        }
        fprintf(f, "+\n");
    }

    static void printTableLine(FILE *fout, const uint32_t *widths, uint32_t size)
    {
        fprintf(fout, "+");
        for (i = 0; i < size; ++i)
        {
            for (j = 0; j < widths[i] + 2; ++j)
                fprintf(fout, "-");
            fprintf(fout, "+");
        }
        fprintf(fout, "\n");
    }

    static void printMemProfile(AddressSpaceProfile *memProfile, FILE *f)
    {
        uint32_t size = sizeof(memProfile->size) / sizeof(memProfile->size[0]);

        for (i = 0; i < size; ++i)
        {
            if (i < memProfile->segmentCount)
            {
                uint32_t n = memProfile->size[i];
                fprintf(f, " %7u ", n);
            }
            else
            {
                fprintf(f, " %7s ", "  ---  ");
            }

            if (i != size - 1)
            {
                fprintf(f, ":");
            }
        }
        fprintf(f, "|");
    }

    static void printMemMapping(AddressSpaceMapping *memMapping, FILE *f)
    {
        uint32_t size = sizeof(memMapping->address) / sizeof(memMapping->address[0]);

        for (i = 0; i < size; ++i)
        {
            if (i < memMapping->blockCount)
            {
                uint32_t n = memMapping->address[i];
                fprintf(f, " %#09x ", n);
            }
            else
            {
                fprintf(f, " %7s ", "   ---   ");
            }

            if (i != size - 1)
            {
                fprintf(f, ":");
            }
        }
        fprintf(f, "|\n");
    }

    static void printFinishTime(FILE *fout, PctNode *current)
    {
        uint32_t finishTime = current->pcb.finishTime;

        if (finishTime == NO_TIME)
            fprintf(fout, "   ---   |");
        else
            fprintf(fout, "  %6u |", finishTime);
    }

    static void printActivationTime(FILE *fout, PctNode *current)
    {
        uint32_t activationTime = current->pcb.activationTime;

        if (activationTime == NO_TIME)
            fprintf(fout, "   ---   |");
        else
            fprintf(fout, "  %6u |", activationTime);
    }

    // ================================================================================== //

} // end of namespace group
