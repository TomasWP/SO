/*
 *  \author Diogo Borges
 */

#include "somm23.h"

namespace group 
{

// ================================================================================== //

    void pctTerm() 
    {
        soProbe(302, "%s()\n", __func__);

        /* TODO POINT: Replace next instruction with your code */
        PctNode* temp;
        while (pctHead != NULL){
            temp = pctHead;          
            pctHead = pctHead->next; 
            free(temp);             
        }
        pctHead = NULL;
    }
// ================================================================================== //

} // end of namespace group

