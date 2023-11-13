/*
 *  \author ...
 */

#include "somm23.h"

#include <stdint.h>

namespace group 
{

// ================================================================================== //

    AddressSpaceMapping *memAlloc(uint32_t pid, AddressSpaceProfile *profile)
    {
        soProbe(504, "%s(%u, %p)\n", __func__, pid, profile);

        require(pid > 0, "process ID must be non-zero");
        require(profile != NULL, "profile must be a valid pointer to an AddressSpaceProfile variable");

        /* TODO POINT: Replace next instruction with your code */
        throw Exception(ENOSYS, __func__);
    }

// ================================================================================== //

} // end of namespace group

