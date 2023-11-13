/*
 *  \author ...
 */

#include "somm23.h"

#include <stdint.h>

namespace group 
{

// ================================================================================== //

    void memInit(uint32_t mSize, uint32_t osSize, uint32_t cSize, AllocationPolicy policy) 
    {
        const char *pas = policy == FirstFit ? "FirstFit" : policy == BuddySystem ? "BuddySystem" : "Unkown";
        soProbe(501, "%s(0x%x, 0x%x, 0x%x, %s)\n", __func__, mSize, osSize, cSize, pas);

        require(mSize > osSize, "memory must be bigger than the one use by OS");
        require((mSize % cSize) == 0, "memory size must be a multiple of chunck size");
        require((osSize % cSize) == 0, "memory size for OS must be a multiple of chunck size");
        require(policy == FirstFit or policy == BuddySystem, "policy must be FirstFit or BuddySystem");

        /* TODO POINT: Replace next instruction with your code */
        throw Exception(ENOSYS, __func__);
    }

// ================================================================================== //

} // end of namespace group

