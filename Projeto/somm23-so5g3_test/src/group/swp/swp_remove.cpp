/*
 *  \author: Tomás Sousa Fonseca 107245
 */

#include "somm23.h"
#include <cstdio>
#include <cstdlib>

namespace group
{

// ================================================================================== //

    void swpRemove(uint32_t idx)
        {
            soProbe(406, "%s(%u)\n", __func__, idx);

            try {
                // Verificar se existe algum evento
                if (swpHead == NULL) {
                    throw Exception(EINVAL, "The swapped processes queue is empty");
                }

                if (idx == 0) {
                    SwpNode* temp = swpHead;
                    if (swpHead == swpTail){
                        swpHead = NULL;
                        swpTail = NULL;
                    } else {
                        swpHead = swpHead->next;
                    }
                    delete temp;
                } else {
                    SwpNode* current = swpHead;
                    SwpNode* previous = NULL;

                    for (uint32_t i = 0; i < idx && current != NULL; ++i) {
                        previous = current;
                        current = current->next;
                    }

                    if (current == NULL) {
                        throw Exception(EINVAL, "Invalid index for swpRemove");
                    }

                    if (current == swpTail){
                        swpTail = previous;     
                    }
                    previous->next = current->next;
                    delete current;
                }

            } catch (const Exception& e) {
                throw e;
            }
    }

// ================================================================================== //

} // end of namespace group

