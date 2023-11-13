/**
 * \defgroup swp Swapped Process Queue (swp)
 *
 * \details 
 *   At the time a process arrives to the system, maybe there is not enough main memory
 *   available to store its address space.
 *   In such a case, the process' address space is stored in the swapped area until main memory
 *   becomes available.
 *
 *   The Swapped Process Queue (\c swp) module is responsible for storing the process' data.
 *   Insertion in this queue is always done at its end (tail).
 *   Peeking and removal can be done at any position.
 *
 *   The supporting data structure is a single linked list implemented from scratch in this module.
 *   The list must be kept sorted according to the insertion order.
 *
 *   The following table presents a list of the functions in this module, including:
 *   - the function name;
 *   - the function ID, that can be used to switch between the binary and group version;
 *   - an estimation of the effort required to implement it;
 *   - a brief description of the function role.
 *   <table>
 *   <tr> <th> \c function <th align="center"> function ID <th align="center"> effort <th>role
 *   <tr> <td> \c swpInit() <td align="center"> 401 <td align="center"> --- <td> Initializes the support internal data structure;
 *   <tr> <td> \c swpClose() <td align="center"> 402 <td align="center"> --- <td> Free and reset the support internal data structure;
 *   <tr> <td> \c swpPrint() <td align="center"> 403 <td align="center"> --- <td> Prints the internal state of the module
 *   <tr> <td> \c swpAdd() <td align="center"> 404 <td align="center"> --- <td> Add a new entry in the tail of the queue
 *   <tr> <td> \c swpPeek() <td align="center"> 405 <td align="center"> --- <td> Peek the entry at the given position
 *   <tr> <td> \c swpRemove() <td align="center"> 406 <td align="center"> --- <td> Remove the entry at the given position
 *   </table>
 *
 *  \author Artur Pereira - 2023
 */

#ifndef __SOMM23_SWP__
#define __SOMM23_SWP__

#include "tme.h"

#include <stdint.h>

/** @{ */

// ================================================================================== //

/**
 * \brief Node for the list of swapped processes
 * \details
 */
struct SwpNode
{
    SwappedProcess process;         ///< a process swapped
    struct SwpNode *next;           ///< pointer no next node
};

// ================================================================================== //

extern SwpNode *swpHead;    ///< Pointer to head of list
extern SwpNode *swpTail;    ///< Pointer to tail of list

// ================================================================================== //

/**
 * \brief Initializes the internal data structure
 * \details
 *  The module's internal data structure, defined in file \c swp.cpp, 
 *  should be initialized properly.<br>
 *  The following must be considered:
 *     
 * \effort 0 (none)
 *
 */
void swpInit();

// ================================================================================== //

/**
 * \brief Free dynamic memory used by the module and reset supporting data structures
 */
void swpClose();

// ================================================================================== //

/**
 * \brief Prints the internal state of the process event queue to the given file
 * \details
 *  The current state of the swapped processes queue (SWP) must be
 *  printed to the given stream.<br>
 *  The following must be considered:
 *  - The output must be exactly the same as the one produced by the binary version.
 *  - In case of an error, an appropriate exception must be thrown.
 *  - All exceptions must be of the type defined in this project (Exception).
 *
 * \param [in] fout File stream where to send output 
 */
void swpPrint(FILE *fout);

// ================================================================================== //

/**
 * \brief Add a new entry in the tail of the queue
 * \details
 *  Dinamically creates a new node and append it to the end of the linked list.<br>
 *  The following must be considered:
 *  - If an anomalous situation occurs, an appropriate exception must be thrown.
 *  - All exceptions must be of the type defined in this project (Exception).
 *  
 * \param [in] pid Id of the process associated to the event
 * \param [in] profile Pointer to a variable containing the process' address space profile
 */
void swpAdd(uint32_t pid, AddressSpaceProfile *profile);

// ================================================================================== //

/**
 * \brief Peek the entry at the given position
 * \details
 *  The event to be selected is the one with earliest event time, covered by the given event mask.
 *  In case two or more events match the aforementioned condition, the one earliest inserted into
 *  the queue is the one selected.<br>
 *  The following must be considered:
 *  - The event <b>must not be removed</b> from the queue.
 *  - The \c EINVAL exception should be thrown, if no event exists.
 *  - All exceptions must be of the type defined in this project (Exception).
 *
 * \param [in] idx Index of the position to be retrieved
 * \return a pointer to the required swapped process
 */
SwappedProcess *swpPeek(uint32_t idx);

// ================================================================================== //

/**
 * \brief Remove the entry at the given position
 * \details
 *  The event to be selected is the one with earliest event time, covered by the given event mask.
 *  In case two or more events match the aforementioned condition, the one earliest inserted into
 *  the queue is the one selected.<br>
 *  The following must be considered:
 *  - The event <b>must be removed</b> from the queue.
 *  - The \c EINVAL exception should be thrown, if no event exists.
 *  - All exceptions must be of the type defined in this project (Exception).
 *
 * \param [in] idx Index of the position to be retrieved
 */
void swpRemove(uint32_t idx);

// ================================================================================== //

/** @} */

#endif /* __SOMM23_SWP__ */

