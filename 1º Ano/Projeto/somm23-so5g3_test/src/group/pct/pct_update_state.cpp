/*
 *  \author Diogo Borges - 102954
 */

#include "somm23.h"

#include <stdint.h>

#include <stdexcept>

namespace group 
{
// ================================================================================== //

    void pctUpdateState(uint32_t pid, ProcessState state, uint32_t time = NO_TIME, AddressSpaceMapping *mapping = NULL)
    {
        soProbe(309, "%s(%d, %u, %u)\n", __func__, pid, state, time);

        require(pid > 0, "a valid process ID must be greater than zero");

        PctNode* current = pctHead;
        while (current != NULL && current->pcb.pid != pid) {
            current = current->next;
        }

        if (current == NULL) {
            throw Exception(EINVAL, __func__);
        }

        current->pcb.state = state;
        if (state == ACTIVE) {
            if (time == NO_TIME || mapping == NULL) {
                throw Exception(EINVAL, __func__);
            }
            current->pcb.activationTime = time;
            current->pcb.memMapping = *mapping;
        } else if (state == FINISHED) {
            current->pcb.finishTime = time;
        }
    }

// ================================================================================== //

} // end of namespace group

