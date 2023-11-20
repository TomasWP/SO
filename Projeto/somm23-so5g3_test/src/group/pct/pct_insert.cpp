/*
 *  \author ...
 */

#include "somm23.h"

#include <stdint.h>

namespace group 
{

// ================================================================================== //

    void pctInsert(uint32_t pid, uint32_t time, uint32_t lifetime, AddressSpaceProfile *profile)
    {
        soProbe(304, "%s(%d, %u, %u, %p)\n", __func__, pid, time, lifetime, profile);

        require(pid > 0, "a valid process ID must be greater than zero");
        require(time >= 0, "time must be >= 0");
        require(lifetime > 0, "lifetime must be > 0");
        require(profile != NULL, "profile must be a valid pointer to a AddressSpaceProfile");

        /* TODO POINT: Replace next instruction with your code */
        throw Exception(ENOSYS, __func__);
    }

// ================================================================================== //

} // end of namespace group

