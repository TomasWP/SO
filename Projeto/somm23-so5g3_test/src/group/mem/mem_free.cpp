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
        
        require(mapping != NULL, "mapping must be a valid pointer");

        for (uint32_t i = 0; i < mapping->blockCount; i++) {
            // Get the address of the current block
            Address blockAddress = mapping->address[i];

            if (memParameters.policy == FirstFit) {
                memFirstFitFree(blockAddress); 
            } else {
                memBuddySystemFree(blockAddress); 
            }
        }
    }

// ================================================================================== //

} // end of namespace group

