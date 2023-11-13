/*
 *  \author ...
 */

#include "somm23.h"

#include <stdint.h>

namespace group 
{

// ================================================================================== //

    void memFirstFitFree(Address address)
    {
        soProbe(508, "%s(%u)\n", __func__, address);

        require(memOccupiedHead != NULL, "Occupied list should contain nodes");

        /* TODO POINT: Replace next instruction with your code */
        throw Exception(ENOSYS, __func__);
    }

// ================================================================================== //

} // end of namespace group

