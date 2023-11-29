/*
 *  BEATRIZ FERREIRA 107214
 */

#include "somm23.h"

namespace group
{

// ================================================================================== //

    /*
     * \brief Init the module's internal data structure
     */
    
    void swpInit()
    {
         /* TODO POINT: Replace next instruction with your code */
        soProbe(401, "%s()\n", __func__);

        swpHead = NULL;
        swpTail = NULL;

    }

// ================================================================================== //

} // end of namespace group