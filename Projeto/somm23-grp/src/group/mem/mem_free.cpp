/*
 *  \author ...
 */

#include "somm23.h"

#include <stdint.h>

namespace group 
{

// ================================================================================== //

    void memFree(AddressSpaceMapping *mapping)
    {
        soProbe(507, "%s(mapping: %p)\n", __func__, mapping);

        require(mapping != NULL, "mapping must be a valid pointer to a AddressSpaceMapping");

        /* TODO POINT: Replace next instruction with your code */
        throw Exception(ENOSYS, __func__);
    }

// ================================================================================== //

} // end of namespace group

