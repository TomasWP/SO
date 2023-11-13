/*
 *  \author Artur Pereira (artur at ua dot pt)
 */

#include "feq.h"

#include <stdio.h>
#include <stdint.h>

// ================================================================================== //

/*
 * The set of supporting variables are NOT changeable
 */
FeqEventNode *feqHead = NULL;

// ================================================================================== //

namespace binaries {
    void feqInit();
    void feqClose();
    void feqPrint(FILE *fout);
    void feqInsert(FutureEventType type, uint32_t time, uint32_t pid);
    FutureEvent feqPop();
}

namespace group {
    void feqInit();
    void feqClose();
    void feqPrint(FILE *fout);
    void feqInsert(FutureEventType type, uint32_t time, uint32_t pid);
    FutureEvent feqPop();
}

// ================================================================================== //

void feqInit()
{
    if (soBinSelected(201))
        binaries::feqInit();
    else
        group::feqInit();
}

// ================================================================================== //

void feqClose()
{
    if (soBinSelected(202))
        binaries::feqClose();
    else
        group::feqClose();
}

// ================================================================================== //

void feqPrint(FILE *fout)
{
    if (soBinSelected(203))
        binaries::feqPrint(fout);
    else
        group::feqPrint(fout);
}

// ================================================================================== //

void feqInsert(FutureEventType type, uint32_t time, uint32_t pid)
{
    if (soBinSelected(204))
        binaries::feqInsert(type, time, pid);
    else
        group::feqInsert(type, time, pid);
}

// ================================================================================== //

FutureEvent feqPop()
{
    if (soBinSelected(205))
        return binaries::feqPop();
    else
        return group::feqPop();
}

// ================================================================================== //

