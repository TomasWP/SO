/**
 * \defgroup mem Memory Management (mem)
 *
 * \details
 *   Initially, the memory is empty, meaning that no process address space is hosted there.
 *   Thus, memory can be seen as a single region with a given dimension.
 *   In order for a process to be executed, one or more blocks of memory must be assigned to it,
 *   in order to host the process' address space segments.
 *   Every segment must be allocated in a continuous block of main memory.
 *
 *   The initial empty region is splitted such that there is a block for
 *   every segment of the process.
 *   To more processes have their address spaces hosted in memory, the empty part is
 *   successively divided.
 *   The way this division is done depends on the allocation policy used.
 *
 *   A running process eventually terminates its execution.
 *   Then, its assigned blocks of memory can be released, becoming available to other processes.
 *   The list of free blocks must be updated to include the released memory.
 *   Every released block may be adjacent to a existent free block or not.
 *   If it is adjacent, a merging must take place.
 *   Otherwise, a new element must be added to the list.
 *
 *   For the first fit approach,
 *   one can see the memory as a set of used blocks plus a set of available
 *   blocks, managing it with two lists:
 *   (a) a list of blocks allocated and assigned to processes;
 *   (b) list of free (not used) blocks.
 *   Both lists must be sorted in ascending order of memory addresses.
 *
 *   For the buddy system approach,
 *   the memory is splitted into halves until a block has enough size to host a segment
 *   but half of it has not.
 *
 *   In order to minimize its external fragmentation, memory is managed in chunks bigger
 *   than a single byte.
 *   This means that the amount of memory assigned to the process is the round up
 *   of the required amount to the chunk size.
 *
 *   The following table presents a list of the functions in this module, including:
 *   - the function name;
 *   - the function ID, that can be used to switch between the binary and group version;
 *   - an estimation of the effort required to implement it;
 *   - a brief description of the function role.
 *   <table>
 *   <tr> <th> \c function <th align="center"> function ID <th align="center"> effort <th>role
 *   <tr> <td> \c memInit() <td align="center"> 501 <td align="center"> --- <td> Initialize the internal data structure of the MEM module
 *   <tr> <td> \c memClose() <td align="center"> 502 <td align="center"> --- <td> Free dynamic memory used by the allocation algorithm and reset supporting data structures
 *   <tr> <td> \c memPrint() <td align="center"> 503 <td align="center"> --- <td> Print the internal state of the memory management module
 *   <tr> <td> \c memAlloc() <td align="center"> 504 <td align="center"> --- <td> Try to allocate the address space profile of a process, using the active allocation policy
 *   <tr> <td> \c memFirstFitAlloc() <td align="center"> 505 <td align="center"> --- <td> Try to allocate a block of memory of the given size, using the first fit algorithm
 *   <tr> <td> \c memBuddySystemAlloc() <td align="center"> 506 <td align="center"> --- <td> Try to allocate a block of memory of the given size, using the buddy system algorithm
 *   <tr> <td> \c memFree() <td align="center"> 507 <td align="center"> --- <td> Free a previously allocated address space mapping
 *   <tr> <td> \c memFirstFitFree() <td align="center"> 508 <td align="center"> --- <td> Free a previously allocated (first fit) block of memory
 *   <tr> <td> \c memBuddySystemFree() <td align="center"> 509 <td align="center"> --- <td> Free a previously allocated (buddy system) block of memory
 *   </table>
 *
 *  \author Artur Pereira - 2023
 */


#ifndef __SOMM23_MEM__
#define __SOMM23_MEM__

#include "tme.h"

#include <stdint.h>

/** @{ */

// ================================================================================== //

/**
 * \brief Global memory parameters
 */
struct MemParameters {
    uint32_t chunkSize;      ///< The number of bytes of the unit of allocation
    uint32_t totalSize;      ///< The total amount of memory in bytes
    uint32_t kernelSize;     ///< The amount of memory used by the operating system
    AllocationPolicy policy; ///< The allocation policy in use
};

// ================================================================================== //

/**
 * \brief A memory block
 */
struct MemBlock {
    uint32_t pid;       ///< The PID of the process using the block; 0 if free
    uint32_t size;      ///< The size in bytes of the block
    Address address;    ///< The start address of the block
};

// ================================================================================== //

/**
 * \brief The node to support the linked lists used by the first fit algorithm
 */
struct MemListNode {
    MemBlock block;                 ///< A block o memory
    struct MemListNode *prev;       ///< A pointer to the previous node
    struct MemListNode *next;       ///< A pointer to the next node
};

// ================================================================================== //

/**
 * \brief The node to support the binary tree used by the buddy system algorithm
 */
struct MemTreeNode {
    uint32_t nodeState;             ///< The state of the node: one of FREE, USED, SPLITTED
    MemBlock block;                 ///< A block o memory
    struct MemTreeNode *left;       ///< A pointer to the left side sub-tree
    struct MemTreeNode *right;      ///< A pointer to the right side sub-tree
};

// ================================================================================== //

extern MemParameters memParameters;     ///< Global memory management parameters

extern MemListNode *memFreeHead;       ///< Head of the free list for first fit algorithm
extern MemListNode *memOccupiedHead;   ///< Head of the occupied list for first fit algorithm

extern MemTreeNode *memTreeRoot; ///< Root of the buddy system tree

// ================================================================================== //

/**
 * \brief Initialize the internal data structure of the MEM module
 * \details
 *  The module's internal data structure, defined in file \c mem.cpp, 
 *  should be initialized appropriately.<br>
 *  The following must be considered:
 *  - In case of an error, an appropriate exception must be thrown.
 *  - All exceptions must be of the type defined in this project (Exception).
 *
 * \effort 2 (low)
 *
 * \param [in] memSize Total amount of memory, in chunks, available
 * \param [in] memSizeOS The amount of memory used by the operating system, in chunks
 * \param [in] chunkSize The unit of allocation, in bytes
 * \param [in] policy The allocation policy to be used
 */
void memInit(uint32_t memSize, uint32_t memSizeOS, uint32_t chunkSize, AllocationPolicy policy);

// ================================================================================== //

/**
 * \brief Free dynamic memory used by the allocation algorithm and reset supporting data structures
 */
void memClose();

// ================================================================================== //

/**
 * \brief Print the internal state of the memory management module
 * \details
 *  The current state of the list of free and of the list of occupied blocks
 *  (module MEM) must be
 *  printed to the given file.<br>
 *  The following must be considered:
 *  - For each list, the printing must be done in ascending order of block address.
 *  - The output must be the same as the one produced by the binary version.
 *  - If print mode is NEW, print to a new file (zapping if necessary).
 *  - If print mode is APPEND, append printing to the end of the file.
 *  - In case of an error, an appropriate exception must be thrown.
 *  - All exceptions must be of the type defined in this project (Exception).
 * \remarks See the result of the binary version, to replicate its behavior
 *
 * \param [in] fout File stream where to send output 
 */
void memPrint(FILE *fout);

// ================================================================================== //

/**
 * \brief Try to allocate the address space profile of a process, using the active allocation policy
 * \details
 *  This is the front end allocation function.
 *  The following must be considered:
 *  - For each segment of the given profile, following the profile order,
 *    the active block allocation function must be called,
 *    in order to fill an address space mapping.
 *  - If one of the segments fail to be allocated, the function should free the previously
 *    allocated blocks, before return NULL.
 *  - If the memory required to allocate the whole address space exceds the total memory for
 *    processes, (void*)(-1) should be returned.
 *  - Each segment size must be rounded up to the smallest multiple of the chunk size.
 *
 * \param [in] pid PID of the process requesting memory
 * \param [in] profile Pointer to a variable containing the process' address space profile
 * \return a valid pointer if succeed; 0 if not enough available memory at the moment; -1 if impossíble
 */
AddressSpaceMapping *memAlloc(uint32_t pid, AddressSpaceProfile *profile);

// ================================================================================== //

/**
 * \brief Try to allocate a block of memory of the given size, using the first fit algorithm
 * \details
 *  This function may assume that the given size was already rounded up by the 
 *  front end allocation function.<br>
 *  The following must be considered:
 *  - In case of an error, an appropriate exception must be thrown.
 *  - All exceptions must be of the type defined in this project (Exception).
 *
 * \param [in] pid PID of the process requesting memory
 * \param [in] size Size of the block to be allocated, in bytes
 * \return The start address of the block allocated
 */
Address memFirstFitAlloc(uint32_t pid, uint32_t size);

// ================================================================================== //

/**
 * \brief Try to allocate a block of memory of the given size, using the buddy system algorithm
 * \details
 *  This function may assume that the given size was already rounded up by the 
 *  front end allocation function.<br>
 *  The following must be considered:
 *  - In case of an error, an appropriate exception must be thrown.
 *  - All exceptions must be of the type defined in this project (Exception).
 *
 * \param [in] pid PID of the process requesting memory
 * \param [in] size Size of the block to be allocated, in bytes
 * \return The start address of the block allocated
 */
Address memBuddySystemAlloc(uint32_t pid, uint32_t size);

// ================================================================================== //

/**
 * \brief Free a previously allocated address space mapping
 * \details
 *  All blocks of the mapping must be free, using the active allocation policy.
 *
 *  The following must be considered:
 *  - In case of an error, an appropriate exception must be thrown.
 *  - All exceptions must be of the type defined in this project (Exception).
 *
 * \param [in] mapping Pointer to a variable containig the address space mapping to be freed
 */
void memFree(AddressSpaceMapping *mapping);

// ================================================================================== //

/**
 * \brief Free a previously allocated (first fit) block of memory
 * \details
 *
 *  If the block to be freed is contiguous to an empty block, merging must take place.
 *  The following must be considered:
 *  - In case of an error, an appropriate exception must be thrown.
 *  - All exceptions must be of the type defined in this project (Exception).
 *
 * \param [in] address Start address of the block to be freed
 */
void memFirstFitFree(Address address);

// ================================================================================== //

/**
 * \brief Free a previously allocated (buddy system) block of memory
 * \details
 *
 *  If the block to be freed is contiguous to an empty block, merging must take place.
 *  The following must be considered:
 *  - In case of an error, an appropriate exception must be thrown.
 *  - All exceptions must be of the type defined in this project (Exception).
 *
 * \param [in] address Start address of the block to be freed
 */
void memBuddySystemFree(Address address);

// ================================================================================== //

/** @} */

#endif /* __SOMM23_MEM__ */


