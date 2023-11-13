/*
 *  \author ...
 */

#include "somm23.h"

namespace group
{

// ================================================================================== //

    void simRandomFill(uint32_t n, uint32_t seed)
    {
        soProbe(105, "%s(%u, %u)\n", __func__, n, seed);

        require(n >= 2, "At least 2 processes are required");

        /* TODO POINT: Replace next instruction with your code */
        throw Exception(ENOSYS, __func__);
    }

// ================================================================================== //

} // end of namespace group

