/*
 *  \author ...
 */

#include "somm23.h"

#include <stdint.h>

namespace group 
{

// ================================================================================== //

    void pctUpdateState(uint32_t pid, ProcessState state, uint32_t time = NO_TIME, AddressSpaceMapping *mapping = NULL)
    {
        soProbe(310, "%s(%d, %u, %u)\n", __func__, pid, state, time);

        require(pid > 0, "a valid process ID must be greater than zero");

        /* TODO POINT: Replace next instruction with your code */
        throw Exception(ENOSYS, __func__);
    }

// ================================================================================== //

} // end of namespace group

