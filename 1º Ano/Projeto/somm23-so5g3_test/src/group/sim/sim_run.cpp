/*
 *  \author ...
 */

#include "somm23.h"

namespace group
{

// ================================================================================== //

    void simRun(uint32_t cnt)
    {
        soProbe(108, "%s(%u)\n", __func__, cnt);

        /* TODO POINT: Replace next instruction with your code */
        if (cnt == 0)
            while(simStep());
        else
            for(uint32_t i = 0; i < cnt && simStep() ; i++);
    }

// ================================================================================== //

} // end of namespace group

