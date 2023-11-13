/*
 *  \author ...
 */

#include "somm23.h"

namespace group
{

// ================================================================================== //

    void simLoad(const char *fname)
    {
        soProbe(104, "%s(\"%s\")\n", __func__, fname);

        require(fname != NULL, "fname can not be a NULL pointer");
        require(forthcomingTable.count == 0, "Forthcoming table should be empty");

        /* TODO POINT: Replace next instruction with your code */
        throw Exception(ENOSYS, __func__);
    }

// ================================================================================== //

} // end of namespace group

