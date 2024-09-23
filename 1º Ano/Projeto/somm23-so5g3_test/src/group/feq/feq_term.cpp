/*
 *  \author Luis Leal
 */

#include "somm23.h"

namespace group
{

    // ================================================================================== //

    void feqTerm()
    {
        soProbe(202, "%s()\n", __func__);

        /* TODO POINT: Replace next instruction with your code */
        // throw Exception(ENOSYS, __func__);

        while (feqHead != NULL)
        {
            struct FeqEventNode *aux = feqHead;
            feqHead = aux->next;
            free(aux);
        }
    }

    // ================================================================================== //

} // end of namespace group
