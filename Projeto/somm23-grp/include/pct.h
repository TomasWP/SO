/**
 * \defgroup pct Process Control Table (pct)
 *
 * \details
 *   The Process Control Table (\c pct) is a mapping that associates a process with a tuple of data.
 *   The process itself is identified by a unique integer value, called Process Identification (\c PID).
 *   To every process, the following data, which represents the process control block (PCB),
 *   is considered:
 *   - the process identification (PID);
 *   - the state of execution, being one of NEW, ACTIVE, SWAPPED, FINISHED, or DISCARDED;
 *   - the time a which the process arrived to the system;
 *   - the lifetime of the process after it is transferred to main memory;
 *   - the time of process activation (transferred to the main memory),
 *     which corresponds to its start of execution;
 *   - the time the process ends its execution;
 *   - the process' address space profile;
 *   - the address mapping, that is where the different address space segments were allocated.
 *
 *   Note that, to be executed, a process needs its address space to be totally resident in memory.
 *   If no free memory, sufficient to host its address space, exist, 
 *   the process must wait until it is available.
 *   Thus, the time at which a process starts to be executed may be different from its arrival time.
 *
 *   The Process Control Table (\c PCT) module is responsible for storing this data
 *   allowing them to be accessed and updated.
 *
 *   The supporting data structure is a single linked list implemented from scratch in this module.
 *   Apart from a \c next pointer, every node contains a process control block (PCB), 
 *   that was already defined above.
 *   The list should be kept sorted in ascending order of the PID.
 *   
 *   The interface of this module is predefined, being composed of the following functions:
 *   <table>
 *   <tr><th>\c function <th align="center"> function ID <th align="center"> effort <th>role
 *   <tr><td>\c pctInit() <td align="center"> 301 <td align="center"> --- <td> Initialize the support internal data structure
 *   <tr><td>\c pctClose() <td align="center"> 302 <td align="center"> --- <td> Free and reset the support internal data structure
 *   <tr><td>\c pctPrint() <td align="center"> 303 <td align="center"> --- <td> Print the internal state of the PCT table
 *   <tr><td>\c pctInsert() <td align="center"> 304 <td align="center"> --- <td> Insert a new entry in the PCT table
 *   <tr><td>\c pctGetLifetime() <td align="center"> 305 <td align="center"> --- <td> Return the time of execution of a process
 *   <tr><td>\c pctGetAddressSpaceProfile() <td align="center"> 306 <td align="center"> --- <td> Return the list of address space segments of the given process
 *   <tr><td>\c pctGetAddressSpaceMapping() <td align="center"> 307 <td align="center"> --- <td> Return the list of memory blocks where the process was allocated 
 *   <tr><td>\c pctGetStateAsString() <td align="center"> 308 <td align="center"> --- <td> Return the state as a string. given the state
 *   <tr><td>\c pctSetAddressSpaceMapping() <td align="center"> 309 <td align="center"> --- <td> Set the list of memory blocks where the process was allocated 
 *   <tr><td>\c pctUpdateState() <td align="center"> 310 <td align="center"> --- <td> Sets the state of a process
 *   </table>
 *
 *  \author Artur Pereira - 2023
 */

#ifndef __SOMM23_PCT__
#define __SOMM23_PCT__

#include "tme.h"

#include <stdint.h>
#include <stdio.h>

/** @{ */

// ================================================================================== //

/**
 * \brief The Process Control Block data structure
 */
struct PctBlock {
    uint32_t pid;                       ///< PID of a process
    ProcessState state;                 ///< The state it is at a given moment
    uint32_t arrivalTime;               ///< The time of its arrival to the system
    uint32_t lifetime;                  ///< The amount of time it needs to be in memory for execution
    uint32_t activationTime;             ///< The time its address space was stored in main memory
    uint32_t finishTime;                ///< The time of its termination
    AddressSpaceProfile memProfile;     ///< Its address space profile
    AddressSpaceMapping memMapping;     ///< Its address space mapping
};

// ================================================================================== //

/**
 * \brief The Process Control Table data structure
 */
//struct PctTable {
//    uint32_t processCount;              ///< Number of processes in the table
//    PctBlock process[MAX_PROCESSES];    ///< The table container
//};

// ================================================================================== //

/**
 * \brief Node for the Process Control Table
 */
struct PctNode {
    PctBlock pcb;           ///< The process control block
    struct PctNode *next;   ///< Pointer to the next node
};

// ================================================================================== //

//extern PctTable pctTable;   ///< The process control table

// ================================================================================== //

extern PctNode *pctHead;    ///< Pointer to head of list 

// ================================================================================== //

/**
 * \brief Initialize the internal data structure
 * \details
 *  The module's internal data structure, defined in file \c pct.cpp, 
 *  should be initialized appropriately.<br>
 *  The following must be considered:
 *     
 * \effort 0 (none)
 *
 */
void pctInit();

// ================================================================================== //

/**
 * \brief Free dynamic memory used by the module and reset supporting data structures
 */
void pctClose();

// ================================================================================== //

/**
 * \brief Print the internal state of the PCT module
 * \details
 *  The current state of the process control table (PCT) must be
 *  printed to the given file stream.<br>
 *  The following must be considered:
 *  - The printing must be done ...
 *  - The output must be the same as the one produced by the binary version.
 *  - In case of an error, an appropriate exception must be thrown.
 *  - All exceptions must be of the type defined in this project (Exception).
 *
 * \param [in] fout File stream where printing must be written to
 */
void pctPrint(FILE *fout);

// ================================================================================== //

/**
 * \brief Add a new entry to the PCT table
 * \details
 *  The first empty entry of the table should be properly filled.
 *
 *  The following must be considered:
 *  - nodes should be kept sorted in ascending order of the PID
 *  - field \c state should be put at \c NEW
 *  - Field \c activationTime should be put at \c NO_TIME
 *  - Field \c finishTime should be put at \c NO_TIME
 *  - Field \c AddressSpaceMapping should be put with an empty mapping
 *  - The \c EINVAL exception should be thrown, if an entry for the given pid already exists
 *  - All exceptions must be of the type defined in this project (Exception)
 *  
 * \param [in] pid Id of process associated to the new entry
 * \param [in] time Time at which the process is submitted (arrival)
 * \param [in] lifetime Time the process takes to run, after it is in main memory
 * \param [in] memProfile Process' address space profile
 */
void pctInsert(uint32_t pid, uint32_t time, uint32_t lifetime, AddressSpaceProfile *memProfile);

// ================================================================================== //

/**
 * \brief Get process execution duration
 * \details
 *  The following must be considered:
 *  - The \c EINVAL exception should be thrown, if an entry for the given pid does not exist.
 *  - All exceptions must be of the type defined in this project (Exception).
 *  
 * \param [in] pid PID of the process
 * \return the process' lifetime
 */
uint32_t pctGetLifetime(uint32_t pid);

// ================================================================================== //

/**
 * \brief Get process address space size
 * \details
 *  The following must be considered:
 *  - The \c EINVAL exception should be thrown, if an entry for the given pid does not exist.
 *  - All exceptions must be of the type defined in this project (Exception).
 *  
 * \param [in] pid PID of the process
 * \return a pointer to the process address space size
 */
AddressSpaceProfile *pctGetAddressSpaceProfile(uint32_t pid);

// ================================================================================== //

/**
 * \brief Get process execution memory address
 * \details
 *  The following must be considered:
 *  - The \c EINVAL exception should be thrown, if an entry for the given pid does not exist.
 *  - All exceptions must be of the type defined in this project (Exception).
 *  
 * \param [in] pid PID of the process
 * \return a pointer to the process' address space mapping
 */
AddressSpaceMapping *pctGetAddressSpaceMapping(uint32_t pid);

// ================================================================================== //

/**
 * \brief Return the process state as a C-string (const char*)
 * \details
 *  The following must be considered:
 *  - The \c EINVAL exception should be thrown, if an entry for the given pid does not exist.
 *  - All exceptions must be of the type defined in this project (Exception).
 *  
 * \param [in] pid PID of the process
 * \return The process state as a string
 */
const char *pctGetStateAsString(uint32_t pid);

// ================================================================================== //

/**
 * \brief Set process execution memory address
 * \details
 *  The following must be considered:
 *  - The \c EINVAL exception should be thrown, if an entry for the given pid does not exist.
 *  - All exceptions must be of the type defined in this project (Exception).
 *  
 * \param [in] pid PID of the process
 * \param [in] mapping Pointer to a structure containing the process' address space mapping
 */
void pctSetAddressSpaceMapping(uint32_t pid, AddressSpaceMapping *mapping);

// ================================================================================== //

/**
 * \brief Set process state
 * \details
 *  The following must be considered:
 *  - If state is ACTIVE, time is the start time
 *  - If state is FINISHED, time is the finish time
 *  - If state is SWAPPED or DISCARDED, time is irrelevant
 *  - The \c EINVAL exception should be thrown, if an entry for the given pid does not exist.
 *  - All exceptions must be of the type defined in this project (Exception).
 *  
 * \param [in] pid PID of the process
 * \param [in] state The process new state
 * \param [in] time The time associated to the change of state
 * \param [in] mapping The mappinf, if state is ACTIVE
 */
void pctUpdateState(uint32_t pid, ProcessState state, uint32_t time = NO_TIME, AddressSpaceMapping *mapping = NULL);

// ================================================================================== //

/** @} */

#endif /* __SOMM23_PCT__ */

