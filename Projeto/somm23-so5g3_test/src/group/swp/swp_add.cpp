/*
 *  \author: Tomás Sousa Fonseca 107245
 */

#include "somm23.h"

namespace group {

void swpAdd(uint32_t pid, AddressSpaceProfile* profile) {
    soProbe(404, "%s(%u, %p)\n", __func__, pid, profile);

    try {
        // Check for valid process ID and profile pointer
        require(pid > 0, "A valid process ID must be greater than zero");
        require(profile != nullptr, "Profile must be a valid pointer to an AddressSpaceProfile");

        // Create a new entry and add it to the end of the linked list
        SwpNode* newEntry = new SwpNode;
        newEntry->process.pid = pid;
        newEntry->process.profile = *profile;
        newEntry->next = NULL;

        if (swpHead == NULL) {
            swpHead = newEntry;
            swpTail = newEntry;
        } else {
            swpTail->next = newEntry;
            swpTail = newEntry;
        }

    } catch (const Exception& e) {
        // Propagate exceptions
        throw e;
    }
}

} // end of namespace group
