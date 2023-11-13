/*
 *  \author ...
 */

#include "somm23.h"

namespace group
{

// ================================================================================== //

    void swpAdd(uint32_t pid, AddressSpaceProfile *profile)
    {
        soProbe(404, "%s(%u, %p)\n", __func__, pid, profile);

        require(pid > 0, "a valid process ID must be greater than zero");
        require(profile != NULL, "profile must be a valid pointer to a AddressSpaceProfile");

        /* TODO POINT: Replace next instruction with your code */
        throw Exception(ENOSYS, __func__);
    }

// ================================================================================== //

} // end of namespace group

