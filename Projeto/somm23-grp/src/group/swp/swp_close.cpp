/*
 *  \author ...
 */

#include "somm23.h"

namespace group
{

// ================================================================================== //

    void swpClose()
    {
        soProbe(402, "%s()\n", __func__);

        /* TODO POINT: Replace next instruction with your code */
        throw Exception(ENOSYS, __func__);
    }

// ================================================================================== //

} // end of namespace group

