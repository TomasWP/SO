/*
 *  \author ...
 */

#include "somm23.h"

namespace group 
{

// ================================================================================== //

    void memTerm() 
    {
        soProbe(502, "%s()\n", __func__);

        while (memFreeHead != NULL) 
        {
            MemListNode* temp = memFreeHead;
            memFreeHead = memFreeHead->next;
            delete temp;
        }
    }

// ================================================================================== //

} // end of namespace group

