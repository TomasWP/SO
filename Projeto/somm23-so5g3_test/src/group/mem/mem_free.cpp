/*
 *  \author: Tomás Sousa Fonseca 107245
 */

#include "somm23.h"

#include <stdint.h>

namespace group 
{

// ================================================================================== //

    void memFree(AddressSpaceMapping *mapping)
    {
        soProbe(507, "%s(mapping: %p)\n", __func__, mapping);

        if (memParameters.policy == FirstFit) {
            memFirstFitFree(*mapping); 
        } else {
            memBuddySystemFree(*mapping); 
        }
    }

// ================================================================================== //

} // end of namespace group

