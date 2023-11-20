/*
 *  \author ...
 */

#include "somm23.h"

#include <stdint.h>

namespace group 
{

// ================================================================================== //

    void memBuddySystemFree(Address address)
    {
        soProbe(509, "%s(%u)\n", __func__, address);

        /* TODO POINT: Replace next instruction with your code */
        throw Exception(ENOSYS, __func__);
    }

// ================================================================================== //

} // end of namespace group

