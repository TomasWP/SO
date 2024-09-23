/*
 *  \author Luis Leal
 */

#include "somm23.h"

namespace group
{

    // ================================================================================== //

    void feqInsert(FutureEventType type, uint32_t time, uint32_t pid)
    {
        const char *tas = type == ARRIVAL ? "ARRIVAL" : type == TERMINATE ? "TERMINATE"
                                                                          : "UNKNOWN";
        soProbe(204, "%s(%s, %u, %u)\n", __func__, tas, time, pid);

        require(pid > 0, "process ID must be non-zero");
        /* TODO POINT: Replace next instruction with your code */

        if (time < 0) throw Exception(EINVAL, __func__);

        FeqEventNode *new_node = (FeqEventNode *)malloc(sizeof(FeqEventNode));
        if (new_node == NULL) throw Exception(ENOMEM, __func__);

        new_node->event.type = type;
        new_node->event.time = time;
        new_node->event.pid = pid;
        new_node->next = NULL;

        if (feqHead == NULL || feqHead->event.time > time || (feqHead->event.time == time && feqHead->event.type != type))
        {
            new_node->next = feqHead;
            feqHead = new_node;
        }
        else
        {
            struct FeqEventNode *current = feqHead;
            while (current->next != NULL &&
                   (current->next->event.time < time ||
                    (current->next->event.time == time &&
                     (type == ARRIVAL || current->next->event.type == type))))
            {
                current = current->next;
            }

            new_node->next = current->next;
            current->next = new_node;
        }

        // throw Exception(ENOSYS, __func__);
    }

    // ================================================================================== //

} // end of namespace group
