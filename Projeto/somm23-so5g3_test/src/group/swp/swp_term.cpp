/*
 *  \author: Tomás Sousa Fonseca 107245
 */

#include "somm23.h"

namespace group
{

// ================================================================================== //

    void swpTerm()
    {
        soProbe(402, "%s()\n", __func__);
        
        while (swpHead != NULL)
        {
            SwpNode *aux = swpHead;
            swpHead = aux->next;
            free(aux);
        }
    }

// ================================================================================== //

} // end of namespace group

