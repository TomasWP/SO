/*
 *  \author Afonso Baixo 108237
 */

#include "somm23.h"
#include <string.h>


namespace group
{

// ================================================================================== //

    void simLoad(const char *fname)
    {
        soProbe(104, "%s(\"%s\")\n", __func__, fname);

        require(fname != NULL, "fname can not be a NULL pointer");
        require(forthcomingTable.count == 0, "Forthcoming table should be empty");

        /* TODO POINT: Replace next instruction with your code */
        FILE *file = fopen(fname, "r");
        if (file == NULL) {
            perror("Error opening file");
            throw Exception(ENOENT, __func__);
        }

        char line[256];
        uint32_t lineNum = 0;

        while (fgets(line, sizeof(line), file)) {            
            // Ignore comments and empty lines
            int is_comment = 0;
            int count_semi_col = 0;

            // Line format -> PID ; Arrival Time ; Lifetime ; AdressSpace1 , AdressSpace2
            for(uint32_t i = 0; line[i] != '\0'; i++) {
                if(line[i] == ';') count_semi_col++;
                else if(line[i] == '%'){
                    is_comment = 1;
                    break;
                }
            }
            if (is_comment || count_semi_col != 3){
                continue;
            }

            // Check if the forthcomingTable has exceeded the maximum limit
            if (forthcomingTable.count+1 >= MAX_PROCESSES) {
                fprintf(stderr, "Error: Exceeded maximum number of processes.\n");
                throw Exception(EINVAL, __func__);
            }
            lineNum++;
            
            ForthcomingProcess *newProcess = (ForthcomingProcess *)malloc(sizeof(ForthcomingProcess));
            if(newProcess == NULL){ throw Exception(ENOMEM, __func__); }

            // Tokenize the line using semi-colon as a delimiter
            char *token;
            // Parse and store the fields in the ForthcomingProcess struct
            token = strtok(line, ";"); // PID 
            newProcess->pid = atoi(token);
            token = strtok(NULL, ";"); // Arrival Time
            newProcess->arrivalTime = atoi(token);
            token = strtok(NULL, ";"); // Lifetime
            newProcess->lifetime = atoi(token);
            token = strtok(NULL, ";"); // Addresspace
            char *segment = strtok(token, ","); // AdressSpace segment
            newProcess->addressSpace.segmentCount = 0;
            while (segment != NULL) {
                newProcess->addressSpace.size[newProcess->addressSpace.segmentCount++] = atoi(segment);
                segment = strtok(NULL, ","); // AdressSpace segment
            }

            // Handle exceptions
            if (newProcess->lifetime <= 0) {
                fprintf(stderr, "Error at process %u: Process lifetime must be greater than zero.\n", lineNum);
                throw Exception(EINVAL, __func__);
            }

            for (uint32_t i = 0; i < forthcomingTable.count; i++) {
                if (newProcess->pid == forthcomingTable.process[i].pid) {
                    fprintf(stderr, "Error at process %u: PIDs should be different.\n", lineNum);
                    throw Exception(EINVAL, __func__);
                }
            }

            // Store the new process in forthcomingTable   
            uint32_t i = 0;
            for(i = 0; newProcess->arrivalTime >= forthcomingTable.process[i].arrivalTime && i < forthcomingTable.count; i++);     
            if(i == forthcomingTable.count){
                forthcomingTable.process[forthcomingTable.count++] = *newProcess;
            }
            else{
                // Sort by arrival time
                for(uint32_t j = forthcomingTable.count; j > i; j--){
                    forthcomingTable.process[j] = forthcomingTable.process[j-1];
                }
                forthcomingTable.process[i] = *newProcess;
                forthcomingTable.count++; 
            }
            feqInsert(ARRIVAL, newProcess->arrivalTime, newProcess->pid);
            free(newProcess);
        }

        fclose(file);

    }

// ================================================================================== //

} // end of namespace group