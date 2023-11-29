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
        
        soProbe(401, "%s()\n", __func__);
        try{
            swpHead = NULL;
            swpTail = NULL;
        } catch (const Exception& e) {
            // Propaga exceções
            throw e;
        }
    }

// ================================================================================== //

} // end of namespace group