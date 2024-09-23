/*
 *  \author Afonso Baixo 108237
 */

#include "somm23.h"

namespace group 
{

// ================================================================================== //

    FutureEvent feqPop()
    {
        soProbe(205, "%s()\n", __func__);

        /* TODO POINT: Replace next instruction with your code */
        if(feqIsEmpty()){
            throw Exception(EINVAL, __func__);
        }
        
        FutureEvent event = feqHead->event;
        FeqEventNode* p1 = feqHead;
        feqHead = feqHead->next;
        free(p1);
        return event;
    }

// ================================================================================== //

    bool feqIsEmpty()
    {
        soProbe(206, "%s()\n", __func__);

        /* TODO POINT: Replace next instruction with your code */
        return feqHead == NULL;
    }

// ================================================================================== //

} // end of namespace group

