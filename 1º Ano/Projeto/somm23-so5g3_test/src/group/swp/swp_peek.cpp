/*
 *  BEATRIZ FERREIRA 107214
 */

#include "somm23.h"

namespace group {

// ================================================================================== //

SwappedProcess* swpPeek(uint32_t idx) {
    
    soProbe(405, "%s(%u)\n", __func__, idx);

    /* TODO POINT: Replace next instruction with your code */
    try {
        if (swpHead == NULL) {
            return NULL;
        }

        uint32_t count = 0;
        SwpNode* current = swpHead;

        while (current != NULL) {
            if (count == idx) {
                return &(current->process);
            }
            count++;
            current = current->next;
        }

        return NULL;
    } catch (const Exception& e) {
        throw e;
    }
}

// ================================================================================== //

} // end of namespace group

