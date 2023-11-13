/**
 * \defgroup feq Future Event Queue (feq)
 *
 * \details 
 *   During a simulation, two different type of events can make the system change state:
 *   - the arrival of a process;
 *   - the end of execution of a process that is running;
 *
 *   The Future Event Queue (\c feq) module is responsible for storing these events and
 *   allowing them to be accessed in specific order.
 *
 *   The supporting data structure is a single linked list implemented from scratch in this module.
 *   Apart from a \c next pointer, every node is composed of:
 *   - the identification of the associated process (\c PID).
 *   - the time at which the event will occur;
 *   - the type of event, being one of arrival (\c ARRIVAL), or termination (\c TERMINATE);
 *   
 *   The list must be kept sorted according to the following criteria:
 *   - the list elements should be sorted in ascending order of event time;
 *   - for elements with the same time stamp, TERMINATE events should appear before ARRIVAL events;
 *   - for elements with the same time stamp and the same type, order of insertion should be preserved.
 *
 *   The following table presents a list of the functions in this module, including:
 *   - the function name;
 *   - the function ID, that can be used to switch between the binary and group version;
 *   - an estimation of the effort required to implement it;
 *   - a brief description of the function role.
 *   <table>
 *   <tr> <th> \c function <th align="center"> function ID <th align="center"> effort <th>role
 *   <tr> <td> \c feqInit() <td align="center"> 201 <td align="center"> --- <td> Initializes the support internal data structure;
 *   <tr> <td> \c feqClose() <td align="center"> 202 <td align="center"> --- <td> Free and reset the support internal data structure;
 *   <tr> <td> \c feqPrint() <td align="center"> 203 <td align="center"> --- <td> Prints the internal state of the process event queue.
 *   <tr> <td> \c feqInsert() <td align="center"> 204 <td align="center"> --- <td> Inserts a new event in the queue, keeping the required order
 *   <tr> <td> \c feqPop() <td align="center"> 205 <td align="center"> --- <td> Returns the front event in the queue, removing it from the queue;
 *   </table>
 *
 *  \author Artur Pereira - 2023
 */

#ifndef __SOMM23_FEQ__
#define __SOMM23_FEQ__

#include "tme.h"

#include <stdint.h>

/** @{ */

// ================================================================================== //

/**
 * \brief FEQ list node
 * \details
 *   
 */
struct FeqEventNode
{
    FutureEvent event;              ///< A future event
    struct FeqEventNode *next;      ///< Pointer to next node
};

// ================================================================================== //

extern FeqEventNode *feqHead;       ///< Pointer to head of list

// ================================================================================== //

/**
 * \brief Initializes the internal data structure
 * \details
 *  The module's internal data structure, defined in file \c feq.cpp, 
 *  should be initialized properly.<br>
 *  The following must be considered:
 *   - It can be assumed that the input file is syntactically and semantically correct
 *
 */
void feqInit();

// ================================================================================== //

/**
 * \brief Free dynamic memory used by the module and reset supporting data structures
 */
void feqClose();

// ================================================================================== //

/**
 * \brief Prints the internal state of the FEQ module
 * \details
 *  The current state of the future event queue (FEQ) must be
 *  printed to the given stream.<br>
 *  The following must be considered:
 *  - The output must be the same as the one produced by the binary version.
 *  - In case of an error, an appropriate exception must be thrown.
 *  - All exceptions must be of the type defined in this project (Exception).
 *
 * \effort 0 (none)
 *
 * \param [in] fout File stream where to send output 
 */
void feqPrint(FILE *fout);

// ================================================================================== //

/**
 * \brief Inserts an entry in the queue
 * \details
 *  A new entry should be created and added to the process event queue.
 *
 *  The following must be considered:
 *  - the list's elements should be sorted in ascending order of event time;
 *  - for elements with the same time stamp, TERMINATE events should appear before ARRIVAL events;
 *  - for elements with the same time stamp and the same type, order of insertion should be preserved.
 *  - If an anomalous situation occurs, an appropriate exception must be thrown.
 *  - All exceptions must be of the type defined in this project (Exception).
 *  
 * \param [in] type The type of event to be inserted (one of ARRIVAL or TERMINATE)
 * \param [in] time Time at which the event will occur
 * \param [in] pid Id of the process associated to the event
 */
void feqInsert(FutureEventType type, uint32_t time, uint32_t pid);

// ================================================================================== //

/**
 * \brief Remove and returns the first event from the list
 * \details
 *  The following must be considered:
 *  - The event <b>must be removed</b> from the queue.
 *  - The \c EINVAL exception should be thrown, if no event exists.
 *  - All exceptions must be of the type defined in this project (Exception).
 *
 * \return The first event in the queue
 */
FutureEvent feqPop();

// ================================================================================== //

/** @} */

#endif /* __SOMM23_FEQ__ */

