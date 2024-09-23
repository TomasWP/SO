/*
 *  \author Diogo Borges - 102954
 */

#include "somm23.h"

namespace group 
{

// ================================================================================== //

    void pctTerm() 
    {
        soProbe(302, "%s()\n", __func__);

        PctNode* temp;
        while (pctHead != NULL){
            temp = pctHead;          
            pctHead = pctHead->next; 
            free(temp);             
        }
    }
// ================================================================================== //

} // end of namespace group

