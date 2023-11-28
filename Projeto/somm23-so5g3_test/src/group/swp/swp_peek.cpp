/*
 *  BEATRIZ FERREIRA 107214
 */

#include "somm23.h"

namespace group {

SwappedProcess* swpPeek(uint32_t idx) {
    
    soProbe(405, "%s(%u)\n", __func__, idx);

    /* TODO POINT: Replace next instruction with your code */
    try {
        
        if (swpHead == NULL) {
            return NULL;
        }

        SwpNode* current = swpHead;
        for (uint32_t i = 0; i < idx && current != NULL; ++i) {
            current = current->next;
        }

        return (current != NULL) ? &(current->process) : NULL;

    } catch (const Exception& e) {
        throw e;
    }
}

} // end of namespace group

