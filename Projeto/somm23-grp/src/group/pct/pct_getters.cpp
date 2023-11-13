/*
 *  \author ...
 */

#include "somm23.h"

    namespace group 
    {

// ================================================================================== //

    uint32_t pctGetLifetime(uint32_t pid)
    {
        soProbe(305, "%s(%u)\n", __func__, pid);

        require(pid > 0, "a valid process ID must be greater than zero");

        /* TODO POINT: Replace next instruction with your code */
        throw Exception(ENOSYS, __func__);
    }

// ================================================================================== //

    AddressSpaceProfile *pctGetAddressSpaceProfile(uint32_t pid)
    {
        soProbe(306, "%s(%u)\n", __func__, pid);

        require(pid > 0, "a valid process ID must be greater than zero");

        /* TODO POINT: Replace next instruction with your code */
        throw Exception(ENOSYS, __func__);
    }

// ================================================================================== //

    AddressSpaceMapping *pctGetAddressSpaceMapping(uint32_t pid)
    {
        soProbe(307, "%s(%u)\n", __func__, pid);

        require(pid > 0, "a valid process ID must be greater than zero");

        /* TODO POINT: Replace next instruction with your code */
        throw Exception(ENOSYS, __func__);
    }

// ================================================================================== //

    const char *pctGetStateAsString(uint32_t pid)
    {
        soProbe(308, "%s(%u)\n", __func__, pid);

        require(pid > 0, "a valid process ID must be greater than zero");

        /* TODO POINT: Replace next instruction with your code */
        throw Exception(ENOSYS, __func__);
    }

// ================================================================================== //

} // end of namespace group

