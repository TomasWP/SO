/*
 *  \author Afonso Baixo 108237
 */

#include "somm23.h"

namespace group
{

    // ================================================================================== //

    void simTerm()
    {
        soProbe(102, "%s()\n", __func__);

        /* TODO POINT: Replace next instruction with your code */

        memTerm();
        swpTerm();
        pctTerm();
        feqTerm();

        forthcomingTable.count = 0;
        simTime = 0;
        stepCount = 0;
    }

    // ================================================================================== //

} // end of namespace group
