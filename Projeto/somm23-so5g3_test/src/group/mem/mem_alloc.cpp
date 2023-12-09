/*
 *  \author Diogo Borges - 102954
 */

#include "somm23.h"

#include <stdint.h>
#include <math.h>

namespace group 
{

// ================================================================================== //

    AddressSpaceMapping *memAlloc(uint32_t pid, AddressSpaceProfile *profile)
    {
        soProbe(504, "%s(%u, %p)\n", __func__, pid, profile);

        require(pid > 0, "process ID must be non-zero");
        require(profile != NULL, "profile must be a valid pointer to an AddressSpaceProfile variable");

        /* The mapping to be filled and whose pointer should be returned */
        static AddressSpaceMapping theMapping = {0, {0}};

        /* TODO POINT: Replace next instructions with your code */
        // Reset theMapping for the new allocation
        theMapping.blockCount = profile->segmentCount;
        for (uint32_t i = 0; i < MAX_BLOCKS; ++i) {
            theMapping.address[i] = NULL_ADDRESS;
        }

        // Array to store the rounded sizes of each segment
        uint32_t roundedSizes[profile->segmentCount];

        // Round up each segment size to the nearest multiple of chunk size
        for (uint32_t i = 0; i < profile->segmentCount; ++i) {
            uint32_t originalSize = profile->size[i];
            roundedSizes[i] = (uint32_t)ceil((double)originalSize / memParameters.chunkSize) * memParameters.chunkSize;
        }
        
        // Check if the total size required is greater than available memory
        uint32_t totalSizeRequired = 0;
        for (uint32_t i = 0; i < profile->segmentCount; i++) {
            totalSizeRequired += roundedSizes[i];
            if (totalSizeRequired > (memParameters.totalSize - memParameters.kernelSize)) {
                return IMPOSSIBLE_MAPPING;
            }
        }
   
        // Attempt to allocate memory for each segment
        for (uint32_t i = 0; i < profile->segmentCount; i++) {
            Address blockAddress = (memParameters.policy == FirstFit)
                                   ? memFirstFitAlloc(pid, roundedSizes[i])
                                   : memBuddySystemAlloc(pid, roundedSizes[i]);
            if (blockAddress == NULL_ADDRESS) {
                // Free any previously allocated blocks
                for (uint32_t j = 0; j < i; ++j) {
                    AddressSpaceMapping tempMapping;
                    tempMapping.blockCount = 1;
                    tempMapping.address[0] = theMapping.address[j];
                    memFree(&tempMapping);
                }
                return NO_MAPPING;
            }
            theMapping.address[i] = blockAddress;
        }
        return &theMapping;
    }

// ================================================================================== //

} // end of namespace group

