/*
 *  \author ...
 */

#include "somm23.h"

#include <stdint.h>

namespace group 
{

// ================================================================================== //

    Address memBuddySystemAlloc(uint32_t pid, uint32_t size)
    {
        soProbe(506, "%s(%u, 0x%x)\n", __func__, pid, size);

        require(pid > 0, "a valid process ID must be greater than zero");
        require(size, "the size of a memory segment must be greater then zero");

        /* TODO POINT: Replace next instruction with your code */
        throw Exception(ENOSYS, __func__);
    }

// ================================================================================== //

} // end of namespace group

