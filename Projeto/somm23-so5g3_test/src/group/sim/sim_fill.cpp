/*
 *  \author Luis Leal
 */

#include "somm23.h"
#include <unistd.h>
#include <math.h>

namespace group
{

    // ================================================================================== //

    static int validPID(uint32_t genPID);

    // ================================================================================== //

    void simRandomFill(uint32_t n, uint32_t seed)
    {
        soProbe(105, "%s(%u, %u)\n", __func__, n, seed);

        require(n == 0 or n >= 2, "At least 2 processes are required");
        require(n <= MAX_PROCESSES, "More than MAX_PROCESSES processes not allowed");

        /* TODO POINT: Replace next instruction with your code */
        // throw Exception(ENOSYS, __func__);

        if (seed == 0)
            seed = getpid();

        srand(seed);

        if (n == 0)
            n = (rand() % (MAX_PROCESSES - 1)) + 2;

        uint32_t i;
        uint32_t arrivalTime = 0;
        for (i = 0; i < n; i++)
        {
            uint32_t genPID;
            do
            {
                genPID = (rand() % 65535) + 1;
            } while (!validPID(genPID));
            forthcomingTable.process[i].pid = genPID;

            forthcomingTable.process[i].arrivalTime = arrivalTime;
            arrivalTime += (rand() % 100);

            forthcomingTable.process[i].lifetime = ((rand() % 991) + 10);
            forthcomingTable.process[i].addressSpace.segmentCount = (rand() % MAX_SEGMENTS) + 1;

            uint32_t j;
            for (j = 0; j < forthcomingTable.process[i].addressSpace.segmentCount; j++)
            {
                forthcomingTable.process[i].addressSpace.size[j] = (rand() % 0x701) + 0x100;
            }

            forthcomingTable.count += 1;

            feqInsert(ARRIVAL, forthcomingTable.process[i].lifetime, forthcomingTable.process[i].pid);
        }
    }

    // ================================================================================== //

    int validPID(uint32_t genPID)
    {
        uint32_t i;
        for (i = 0; i < forthcomingTable.count; i++)
        {
            if (forthcomingTable.process[i].pid == genPID)
            {
                return 0;
            }
        }
        return 1;
    }

    // ================================================================================== //

} // end of namespace group
