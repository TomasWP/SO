/*
 *  \author ...
 */

#include "somm23.h"

namespace group
{

// ================================================================================== //

    /*
     * \brief Init the module's internal data structure
     */
    void simInit(uint32_t mSize, uint32_t osSize, uint32_t cSize, AllocationPolicy policy)
    {
        const char *pas = policy == FirstFit ? "FirstFit" : policy == BuddySystem ? "BuddySystem" : "Unkown";
        soProbe(101, "%s(0x%x, 0x%x, 0x%x, %s)\n", __func__, mSize, osSize, cSize, pas);

        /* TODO POINT: Replace next instruction with your code */
        throw Exception(ENOSYS, __func__);
    }

// ================================================================================== //

} // end of namespace group

