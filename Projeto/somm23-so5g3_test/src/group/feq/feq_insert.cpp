/*
 *  \author ...
 */

#include "somm23.h"

namespace group 
{

// ================================================================================== //

    void feqInsert(FutureEventType type, uint32_t time, uint32_t pid)
    {
        const char *tas = type == ARRIVAL ? "ARRIVAL" : type == TERMINATE ? "TERMINATE" : "UNKOWN";
        soProbe(204, "%s(%s, %u, %u)\n", __func__, tas, time, pid);

        require(pid > 0, "process ID must be non-zero");

        /* TODO POINT: Replace next instruction with your code */
        throw Exception(ENOSYS, __func__);
    }

// ================================================================================== //

} // end of namespace group

