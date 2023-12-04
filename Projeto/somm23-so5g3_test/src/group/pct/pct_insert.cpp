/*
 *  \author Paulo Macedo
 */

#include "somm23.h"
#include "tme.h"

#include <stdint.h>

namespace group 
{

// ================================================================================== //

    void pctInsert(uint32_t pid, uint32_t time, uint32_t lifetime, AddressSpaceProfile *profile)
    {
        soProbe(304, "%s(%d, %u, %u, %p)\n", __func__, pid, time, lifetime, profile);

        require(pid > 0, "a valid process ID must be greater than zero");
        require(time >= 0, "time must be >= 0");
        require(lifetime > 0, "lifetime must be > 0");
        require(profile != NULL, "profile must be a valid pointer to a AddressSpaceProfile");

        struct PctNode* newNode = (PctNode*) malloc(sizeof(PctNode));

        if (newNode == NULL) 
            throw Exception(ENOMEM, __func__);

        newNode->pcb.pid = pid;
        newNode->pcb.state = NEW; 
        newNode->pcb.arrivalTime = time;
        newNode->pcb.lifetime = lifetime;
        newNode->pcb.activationTime = NO_TIME;
        newNode->pcb.finishTime = NO_TIME;
        newNode->pcb.memProfile = *profile;
        newNode->pcb.memMapping.blockCount = 0;

        for (int i = 0; i < MAX_BLOCKS; ++i) {
            newNode->pcb.memMapping.address[i] = NULL_ADDRESS; 
        }

        if (pctHead == NULL || pctHead->pcb.pid > pid) {
            newNode->next = pctHead;
            pctHead = newNode;
        } else {
            struct PctNode* current = pctHead;
            while (current->next != NULL && current->next->pcb.pid <= pid) {
                if (current->next->pcb.pid == pid) {
                    free(newNode);
                    throw Exception(EINVAL, __func__);
                }
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

// ================================================================================== //

} // end of namespace group

