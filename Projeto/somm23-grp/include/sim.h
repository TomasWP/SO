/**
 * \defgroup sim Simulation Management (sim)
 *
 * \details
 *  The simulation is driven by an input array (\c forthcomingTable), 
 *  representing a set of processes, that will arrive to the system.
 *
 *  The important data for every process arriving to the system is
 *  the process PID, the time of arrival,
 *  the lifetime in memory and the address space profile (see \ref keyterms).<br>
 *  
 *  This module must keep internally the number of steps already processed and 
 *  the current simulation time.
 *
 *   The supporting data structure is a fixed-size static array.
 *
 *   The following table presents a list of the functions in this module, including:
 *   - the function name;
 *   - the function ID, that can be used to switch between the binary and group version;
 *   - an estimation of the effort required to implement it;
 *   - a brief description of the function role.
 *   <table>
 *   <tr> <th> \c function <th align="center"> function ID <th align="center"> effort <th>role
 *   <tr> <td> \c simInit() <td align="center"> 101 <td align="center"> --- <td> Initializes the simulation
 *   <tr> <td> \c simClose() <td align="center"> 102 <td align="center"> --- <td> Closes the simulation
 *   <tr> <td> \c simPrint() <td align="center"> 103 <td align="center"> --- <td> Prints the contents of the forthcoming table
 *   <tr> <td> \c simLoad() <td align="center"> 104 <td align="center"> --- <td> Fills the forthcoming table from a given file
 *   <tr> <td> \c simRandomFill() <td align="center"> 105 <td align="center"> --- <td> Randomly fills the forthcoming table
 *   <tr> <td> \c simGetProcess() <td align="center"> 106 <td align="center"> --- <td> Get the data of a forthcoming process
 *   <tr> <td> \c simStep() <td align="center"> 107 <td align="center"> --- <td> Run the simulation for one step
 *   <tr> <td> \c simRun() <td align="center"> 108 <td align="center"> --- <td> Run the simulation for a given number of steps
 *   </table>
 *
 *  \author Artur Pereira - 2023
 */

#ifndef __SOMM23_SIM__
#define __SOMM23_SIM__

#include "tme.h"

#include <stdint.h>

/** @{ */

// ================================================================================== //

/** 
 * \brief Description of a process that will arrive to the system
 */
struct ForthcomingProcess {
    uint32_t pid;                       ///< PID of a process
    uint32_t arrivalTime;               ///< The process' arrival time
    uint32_t lifetime;                  ///< The process' lifetime
    AddressSpaceProfile addressSpace;   ///< The process' address space profile
};

// ================================================================================== //

/**
 * \brief Set of processes that will arrive to the system
 */
struct ForthcomingTable {
    uint32_t count;                             ///< Number of processes in the forthcoming table
    ForthcomingProcess process[MAX_PROCESSES];  ///< The array holding the forthcoming table
};

// ================================================================================== //

/**
 * \brief The set of supporting variables are NOT changeable
 */
extern uint32_t stepCount;                  ///< The current number of simulation steps
extern uint32_t simTime;                    ///< The current simulation time
extern ForthcomingTable forthcomingTable;   ///< The set of processes to be simulated

// ================================================================================== //

/**
 * \brief Initializes the internal data structure and init the other modules
 * \details
 *  The module's internal data structure, defined in file \c sim.cpp, 
 *  should be initialized properly.
 *  Also, the other modules should be initialized.
 *
 *  The following must be considered:
 *  - In case of an error, an appropriate exception must be thrown
 *  - All exceptions must be of the type defined in this project (see Exception)
 *
 * \effort 1 (quite low)
 *
 * \param [in] memSize Total amount of memory, in chunks, available
 * \param [in] memSizeOS The amount of memory used by the operating system, in chunks
 * \param [in] chunkSize The unit of allocation, in bytes
 * \param [in] policy The allocation policy to be used
 */
void simInit(uint32_t memSize, uint32_t memSizeOS, uint32_t chunkSize, AllocationPolicy policy);

// ================================================================================== //

/**
 * \brief Close the simulation
 * \details
 *   The other modules must also be closed
 */
void simClose();

// ================================================================================== //

/**
 * \brief Initializes the forthcoming table, parsing an input file
 * \details
 *   - Syntactically, an input file is a sequence of lines,
 *     each one representing a comment or a forthcoming process.
 *   - A line representing a forthcoming process is a semi-colon separeted sequence of the following
 *     fields:
 *     - the PID of a process;
 *     - the time of its arrival to the system;
 *     - the duration of its lifetime;
 *     - its address space profile, which is a comma-separeted sequence of segment sizes.
 *   - Lines starting with an % are comments and are to be ignored
 *   - whitespaces (spaces or tabs) are syntactically irrelevant, and can appear any where
 *   - white lines are also to be ignored
 *
 *  The following must be considered:
 *  - PIDs should be different
 *  - Arrival times should appear in ascending order
 *  - Lifetimes must be greater then zero
 *  - In case of an error, an appropriate exception must be thrown
 *  - If it is a system error, the \c errno error number should be thrown
 *  - If it is a syntax or semantic error, 
 *    an appropriate error message should be printed and the \c EINVAL error number should be thrown
 *  - All exceptions must be of the type defined in this project (Exception)
 *
 *  \effort 4 (medium)
 *
 * \param fname Path to the input file
 */
void simLoad(const char *fname);

// ================================================================================== //

/**
 * \brief Randomly fills the forthcoming table
 * \details
 *   If argument \c n is zero, the number of processes should be randomly selected between 2
 *   and MAX_PROCESSES.
 *   If argument \c seed is zero, the seed of the ramdom number generator should be getpid().
 *
 * \param [in] n The number of processes to generate
 * \param [in] seed The seed for the randon number generator
 */
void simRandomFill(uint32_t n, uint32_t seed);

// ================================================================================== //

/**
 * \brief Prints the contents of the forthcoming table
 * \details
 *  The current contents of the forthcoming table should be
 *  printed to the given stream.<br>
 *  The following must be considered:
 *  - The output must be the same as the one produced by the binary version.
 *  - In case of an error, an appropriate exception must be thrown.
 *  - All exceptions must be of the type defined in this project (Exception).
 *
 *  \effort 3 (low medium)
 *
 * \param [in] fout File stream where to send output 
 */
void simPrint(FILE *fout);

// ================================================================================== //

/**
 * \brief Get data of a forthcoming process, given its PID
 * \param pid The PID of the process whose data is requested
 * \return a pointer to the register containing the data
 */
ForthcomingProcess *simGetProcess(uint32_t pid);

// ================================================================================== //

/**
 * \brief Run a step of the simulation
 * \details
 *  This function is responsible for actually do the simulation, interacting with all
 *  the other modules.
 *  An event should be fetched from the future event queue and processed.
 *  The processing to be done depends on the event type, ARRIVAL or TERMINATE.
 *  An ARRIVAL event firstly cause the addition of a NEW process to the set of active processes.
 *  Then, depending on memory requestements and memory availability, the new process changes state 
 *  to ACTIVE, SWAPPED or DISCARDED.
 *  A TERMINATE event causes the associated process to change state to FINISHED.
 *  Then, because memory is released, some swapped processes can now be activated for execution.
 *  They must be dispatched in order, if memory is available.
 */
void simStep();

// ================================================================================== //

/**
 * \brief Run the simulation for a given number of steps
 * \details
 *  The following must be considered:
 *  - The simulation can reach the end in less than the given number of steps.
 *  - If the given number of steps is zero, the simulation must run til the end.
 *
 * \param [in] cnt Number of simulation steps to execute
 */
void simRun(uint32_t cnt);

// ================================================================================== //

/** @} */

#endif /* __SOMM23_SIM__ */

