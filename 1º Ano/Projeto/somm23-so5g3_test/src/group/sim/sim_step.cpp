/*
 *  \author Afonso Baixo, Luis Leal
 */

#include "somm23.h"

namespace group
{

    // ================================================================================== //

    bool simStep()
    {
        soProbe(107, "%s()\n", __func__);

        /* TODO POINT: Replace next instruction with your code */
        // throw Exception(ENOSYS, __func__);

        if (feqIsEmpty())
            return 0;

        FutureEvent event = feqPop();
        if (event.type == ARRIVAL)
        {
            ForthcomingProcess *proc = simGetProcess(event.pid);
            pctInsert(event.pid, event.time, proc->lifetime, &(proc->addressSpace));

            AddressSpaceMapping *addressSpaceMap = memAlloc(event.pid, &(proc->addressSpace));
            if (addressSpaceMap == IMPOSSIBLE_MAPPING)
            {
                pctUpdateState(event.pid, DISCARDED, NO_TIME, addressSpaceMap);
            }
            else if (addressSpaceMap == NULL_ADDRESS)
            {
                swpAdd(event.pid, &(proc->addressSpace));
                pctUpdateState(event.pid, SWAPPED, event.time, addressSpaceMap);
            }
            else
            {
                feqInsert(TERMINATE, (proc->arrivalTime + proc->lifetime), event.pid);
                pctUpdateState(event.pid, ACTIVE, event.time, addressSpaceMap);
            }
        }

        if (event.type == TERMINATE)
        {
            AddressSpaceMapping *addressSpaceMap = pctGetAddressSpaceMapping(event.pid);
            pctUpdateState(event.pid, FINISHED, event.time, addressSpaceMap);
            memFree(addressSpaceMap);

            uint32_t i = 0;
            uint32_t lifetime;
            SwappedProcess *swpProc = swpPeek(0);
            while (swpProc != NULL)
            {
                AddressSpaceMapping *swpAddressSpaceMap = memAlloc(swpProc->pid, &(swpProc->profile));

                if (swpAddressSpaceMap != NULL_ADDRESS)
                {
                    lifetime = pctGetLifetime(swpProc->pid);
                    feqInsert(TERMINATE, (event.time + lifetime), swpProc->pid);
                    pctUpdateState(swpProc->pid, ACTIVE, event.time, swpAddressSpaceMap);
                    swpRemove(i);
                    swpProc = swpPeek(i);
                }
                else
                {
                    swpProc = swpPeek(++i);
                }
            }
        }

        simTime = event.time;
        stepCount += 1;
        return 1;
    }

    // ================================================================================== //

} // end of namespace group
