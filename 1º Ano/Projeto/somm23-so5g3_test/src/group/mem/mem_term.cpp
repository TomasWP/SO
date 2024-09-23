/*
 *  \author: Tomás Sousa Fonseca 107245
 */

#include "somm23.h"

namespace group 
{

// ================================================================================== //

    void memTerm() 
    {
        soProbe(502, "%s()\n", __func__);
        try{        
            while (memFreeHead != NULL) 
            {
                MemListNode* temp = memFreeHead;
                memFreeHead = memFreeHead->next;
                delete temp;
            }
        } catch (const Exception& e) {
            throw e;
        }
    }

// ================================================================================== //

} // end of namespace group

