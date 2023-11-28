/*
 *  \author ...
 */

#include "somm23.h"

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

            // Remove o processo na posição dada
            if (idx == 0) {
                // Caso seja o primeiro elemento
                SwpNode* temp = swpHead;
                swpHead = swpHead->next;
                delete temp;
            } else {
                // Caso esteja em uma posição diferente
                SwpNode* current = swpHead;
                SwpNode* previous = NULL;

                for (uint32_t i = 0; i < idx && current != NULL; ++i) {
                    previous = current;
                    current = current->next;
                }

                if (current == NULL) {
                    // A posição não existe
                    throw Exception(EINVAL, "Invalid index for swpRemove");
                }

                previous->next = current->next;
                delete current;
            }

        } catch (const Exception& e) {
            // Propaga exceções
            throw e;
        }
    }

// ================================================================================== //

} // end of namespace group

