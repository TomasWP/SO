/*
 *  \author Afonso Baixo 108237
 */

#include "somm23.h"

namespace group
{
    // ================================================================================== //

    static int segment_separator_count = 0;
    static bool isValid(const char *line, uint32_t lineNum);
    static bool isCommented(const char *line);

    // ================================================================================== //

    void simLoad(const char *fname)
    {
        soProbe(104, "%s(\"%s\")\n", __func__, fname);

        require(fname != NULL, "fname can not be a NULL pointer");
        require(forthcomingTable.count == 0, "Forthcoming table should be empty");

        /* TODO POINT: Replace next instruction with your code */
        uint32_t pid, arrivaltime, lifetime;
        uint32_t *sa = (uint32_t *)malloc(sizeof(uint32_t) * 4);

        FILE *file = fopen(fname, "r");
        if (file == NULL)
        {
            fprintf(stderr, "Error opening file");
            throw Exception(errno, __func__);
        }
        uint32_t lineNum = 0;

        if (sa == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            throw Exception(ENOMEM, __func__);
        }

        char *line = NULL;
        size_t s = 0;
        while (getline(&line, &s, file) != -1)
        {
            // Process Line
            lineNum++;
            if (isCommented(line))
            {
                continue;
            }
            bool valid = isValid(line, lineNum);
            if (!valid)
            {
                throw Exception(EINVAL, __func__);
            }

            // Check if the forthcomingTable has exceeded the maximum limit
            if (forthcomingTable.count + 1 >= MAX_PROCESSES)
            {
                fprintf(stderr, "Error: Exceeded maximum number of processes.\n");
                throw Exception(EINVAL, __func__);
            }

            int matched = sscanf(line, " %d ; %d ; %d ; %d , %d , %d , %d ", &pid, &arrivaltime, &lifetime, &sa[0], &sa[1], &sa[2], &sa[3]);
            if (matched < 3)
            {
                fprintf(stderr, "Syntax error at line %d: not enough arguments (%d)\n", lineNum, matched);
                throw Exception(EINVAL, __func__);
            }
            ForthcomingProcess *newProcess = (ForthcomingProcess *)malloc(sizeof(ForthcomingProcess));
            if (newProcess == NULL)
            {
                throw Exception(ENOMEM, __func__);
            }

            newProcess->pid = pid;
            newProcess->arrivalTime = arrivaltime;
            newProcess->lifetime = lifetime;
            newProcess->addressSpace.segmentCount = (matched - 3);
            for (u_int32_t i = 0; i < newProcess->addressSpace.segmentCount; i++)
            {
                newProcess->addressSpace.size[i] = sa[i];
            }
            // Handle exceptions
            for (uint32_t i = 0; i < forthcomingTable.count; i++)
            {
                if (newProcess->pid == forthcomingTable.process[i].pid)
                {
                    fprintf(stderr, "Error at line %u: PIDs should be different.\n", lineNum);
                    throw Exception(EINVAL, __func__);
                }
                if (newProcess->arrivalTime < forthcomingTable.process[i].arrivalTime)
                {
                    fprintf(stderr, "Error at line %u: Arrival times should appear in ascending order.\n", lineNum);
                    throw Exception(EINVAL, __func__);
                }
            }
            if (newProcess->lifetime <= 0)
            {
                fprintf(stderr, "Error at line %u: Process lifetime must be greater than zero.\n", lineNum);
                throw Exception(EINVAL, __func__);
            }

            // Store the new process in forthcomingTable
            forthcomingTable.process[forthcomingTable.count++] = *newProcess;
            feqInsert(ARRIVAL, newProcess->arrivalTime, newProcess->pid);
            free(newProcess);
        }
        fclose(file);
    }

    // ================================================================================== //

    bool isValid(const char *line, uint32_t lineNum)
    {
        const char *ptr;
        int fields_count = 0;
        bool valid_last_char = true;
        for (ptr = line; *ptr != '\n' && *ptr != '\0'; ptr++)
        {
            if (*ptr == ';' && fields_count < 3)
            {
                fields_count++;
            }
            else if (*ptr == ',' && fields_count >= 3)
            {
                fields_count++;
                segment_separator_count++;
                valid_last_char = false;
            }
            else if (*ptr >= '0' && *ptr <= '9')
            {
                valid_last_char = true;
            }
            else if (*ptr != ' ')
            {
                fprintf(stderr, "Syntax error at line %d: invalid character '%c'\n", lineNum, *ptr);
                return false;
            }
        }
        if (fields_count > 6)
        {
            fprintf(stderr, "Syntax error at line %d: too many segments\n", lineNum);
            return false;
        }
        if (!valid_last_char)
        {
            fprintf(stderr, "Syntax error at line %d: invalid end of line\n", lineNum);
            return false;
        }
        return true;
    }

    // ================================================================================== //

    bool isCommented(const char *line)
    {
        const char *ptr;
        for (ptr = line; *ptr != '\n' && *ptr != '\0'; ptr++)
        {
            if (*ptr == '%')
            {
                return true;
            }
            else if (*ptr != ' ')
            {
                return false;
            }
        }
        // White line
        return true;
    }

    // ================================================================================== //

} // end of namespace group