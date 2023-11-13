/*
 *  
 *  ...
 *
 *  \author Artur Pereira - 2023
 */

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>
#include <termios.h>

#include <string>
#include <iostream>
#include <map>

#include "somm23.h"


/* ******************************************** */
/* print help message */
static void printUsage(const char *cmd_name)
{
    printf("Sinopsis: %s [OPTIONS] \n"
           "  OPTIONS:\n"
           "  -i infile     --- set input file (default: none)\n"
           "  -o outfile    --- set output file (default: stdout)\n"
           "  -f buddy      --- set buddy system as the allocation policy (default: first fit)\n"
           "  -k address    --- memory size, in chunks, used by (kernel) OS (default: 0x1000)\n"
           "  -m size       --- total memory size, in chunks, (default: 0x10000)\n"
           "  -c size       --- chunk size (default: 256)\n"
           "  -O outfile    --- set probing file (default: stdout)\n"
           "  -P num-num    --- set probing map to given ID range (default: 0-0)\n"
           "  -A num-num    --- add range of IDs to probing map\n"
           "  -R num-num    --- remove range of IDs from probing map\n"
           "  -b            --- set bin selection map to 100-599\n"
           "  -g            --- set bin selection map to 0-0 (default)\n"
           "  -a num-num    --- add range of IDs to bin selection map\n"
           "  -r num-num    --- remove range of IDs from bin selection map\n"
           "  -h            --- print this help\n", cmd_name);
}

/*
 * pause simulation
 */
bool pauseSim()
{
    static bool firstTime = true;
    static struct termios prev, cur;
    if (firstTime)
    {
        firstTime = false;
        tcgetattr(STDIN_FILENO, &prev);
        cur = prev;
        cur.c_lflag &= (~ICANON);
        tcsetattr(STDIN_FILENO, TCSANOW, &cur);
    }

    printf("Continue (Y/n)? "); fflush(stdout);
    while (true)
    {
        int res = getchar();
        if (res == '\n') break;
        printf("\n");
        if (res == 'n' or res == 'N') return false;
        if (res == 'y' or res == 'Y') break;
        printf("Bad option! Continue (Y/n)? "); fflush(stdout);
    }
    return true;
}

/* ******************************************** */
/* The main function */
int main(int argc, char *argv[])
{
    const char *progName = basename(argv[0]); 

    /* open probing system, all */
    FILE *fout = stdout;
    soProbeOpen(stdout, 0, 0);
    soProbeSetIDs(0, 0);

    /* default values for command line options */
    AllocationPolicy memPolicy = FirstFit;
    uint32_t memChunkSize = 256;
    uint32_t memSize = 0x10000 * memChunkSize;
    uint32_t memSizeOS = 0x1000 * memChunkSize;
    const char *infile = NULL;
    const char *outfile = NULL;

    /* process command line options */
    int opt;
    while ((opt = getopt(argc, argv, "i:o:f:k:m:c:O:P:A:R:bga:r:h")) != -1)
    {
        switch (opt)
        {
            case 'i':       // set input file
            {
                infile = optarg;
                break;
            }
            case 'o':       // set output file
            {
                outfile = optarg;
                if ((fout = fopen(outfile, "w")) == NULL)
                {
                    fprintf(stderr, "%s: Bad argument (%s): fail opening file.\n", progName, optarg);
                    return EXIT_FAILURE;
                }
                break;
            }
            case 'f':
            {
                if (optarg[0] == 'b') memPolicy = BuddySystem;
                break;
            }
            case 'k':          // set memory size used by OS
            {
                int n = 0;
                sscanf(optarg, "%u%n", &memSizeOS, &n);
                if ((size_t)n == strlen(optarg)) break;
                n = 0;
                sscanf(optarg, "%x%n", &memSizeOS, &n);
                if ((size_t)n == strlen(optarg)) break;
                fprintf(stderr, "%s: Bad argument (%s) to '-k' option.\n", progName, optarg);
                return EXIT_FAILURE;
            }
            case 'm':          // set memory size
            {
                int n = 0;
                sscanf(optarg, "%u%n", &memSize, &n);
                if ((size_t)n == strlen(optarg)) break;
                n = 0;
                sscanf(optarg, "%x%n", &memSize, &n);
                if ((size_t)n == strlen(optarg)) break;
                fprintf(stderr, "%s: Bad argument (%s) to '-m' option.\n", progName, optarg);
                return EXIT_FAILURE;
            }
            case 'c':          // set memory chunk size
            {
                int n = 0;
                sscanf(optarg, "%u%*[^\n]%*c%n", &memChunkSize, &n);
                if (n != 0) break;
                n = 0;
                sscanf(optarg, "0%*[xX]%x%*[^\n]%*c%n", &memChunkSize, &n);
                if (n != 0) break;
                fprintf(stderr, "%s: Bad argument (%s) to '-c' option.\n", progName, optarg);
                return EXIT_FAILURE;
            }
            case 'O':          /* set probbing file */
            {
                soProbeFile(optarg);
                break;
            }
            case 'P':          /* set ID range to probing system */
            {
                uint32_t lower, upper;
                uint32_t cnt = 0;
                if ( (sscanf(optarg, "%d%*[,-]%d %n", &lower, &upper, &cnt) != 2) 
                        or (cnt != strlen(optarg)) )
                {
                    fprintf(stderr, "%s: Bad argument to '-p' option.\n", progName);
                    printUsage(progName);
                    return EXIT_FAILURE;
                }
                soProbeSetIDs(lower, upper);
                break;
            }
            case 'A':          /* add IDs to probe conf */
            {
                uint32_t lower, upper;
                uint32_t cnt = 0;
                if ( (sscanf(optarg, "%d%*[,-]%d %n", &lower, &upper, &cnt) != 2) 
                        or (cnt != strlen(optarg)) )
                {
                    fprintf(stderr, "%s: Bad argument to '-A' option.\n", basename(argv[0]));
                    printUsage(basename(argv[0]));
                    return EXIT_FAILURE;
                }
                soProbeAddIDs(lower, upper);
                break;
            }
            case 'R':          /* remove IDs from probe conf */
            {
                uint32_t lower, upper;
                uint32_t cnt = 0;
                if ( (sscanf(optarg, "%d-%d %n", &lower, &upper, &cnt) != 2) 
                        or (cnt != strlen(optarg)) )
                {
                    fprintf(stderr, "%s: Bad argument to '-R' option.\n", basename(argv[0]));
                    printUsage(basename(argv[0]));
                    return EXIT_FAILURE;
                }
                soProbeRemoveIDs(lower, upper);
                break;
            }
            case 'b':  // set binary mode TODO
            {
                soBinSetIDs(100, 599);
                break;
            }
            case 'g':  // set binary mode  TODO
            {
                soBinSetIDs(0, 0);
                break;
            }
            case 'a':          /* add IDs to probe conf */
            {
                uint32_t lower, upper;
                uint32_t cnt = 0;
                if ( (sscanf(optarg, "%d%*[,-]%d %n", &lower, &upper, &cnt) != 2) 
                        or (cnt != strlen(optarg)) )
                {
                    fprintf(stderr, "%s: Bad argument to '-A' option.\n", basename(argv[0]));
                    printUsage(basename(argv[0]));
                    return EXIT_FAILURE;
                }
                soBinAddIDs(lower, upper);
                break;
            }
            case 'r':          /* remove IDs from probe conf */
            {
                uint32_t lower, upper;
                uint32_t cnt = 0;
                if ( (sscanf(optarg, "%d-%d %n", &lower, &upper, &cnt) != 2) 
                        or (cnt != strlen(optarg)) )
                {
                    fprintf(stderr, "%s: Bad argument to '-R' option.\n", basename(argv[0]));
                    printUsage(basename(argv[0]));
                    return EXIT_FAILURE;
                }
                soBinRemoveIDs(lower, upper);
                break;
            }
            case 'h':
            {
                printUsage(progName);
                return 0;
            }
            default:
            {
                fprintf(stderr, "%s: Wrong option (\"-%c\".\n", progName, opt);
                printUsage(progName);
                return EXIT_FAILURE;
            }
        }
    }

    fprintf(fout, "\n");
    fprintf(fout, "\e[34;1mtesting simInit and simPrint with an empty list\e[0m\n");
    simInit(memSize, memSizeOS, memChunkSize, memPolicy);
    simPrint(fout);

    fprintf(fout, "\e[34;1mtesting simLoad and simPrint\e[0m\n");
    simLoad(infile);
    simPrint(fout);
    
    fprintf(fout, "\e[34;1mtesting feqInsert and feqPrint\e[0m\n");
    feqInsert(TERMINATE, 100, 9999);
    feqInsert(ARRIVAL, 1090, 8999);
    feqPrint(fout);

    fprintf(fout, "\e[34;1mtesting feqPop\e[0m\n");
    fprintf(fout, "\n");
    FutureEvent ev = feqPop();
    const char *s = ev.type == ARRIVAL ? "ARRIVAL" : "TERMINATE";
    fprintf(stdout, "time: %u; type: %s; pid: %u\n", ev.time, s, ev.pid);
    fprintf(fout, "\n");
    feqPrint(fout);

    fprintf(fout, "\e[34;1mtesting swpAdd and swpPrint\e[0m\n");
    for (uint32_t i = 0; i < 3; i++)
    {
        ForthcomingProcess *p = &forthcomingTable.process[i];
        swpAdd(p->pid, &p->addressSpace);
    }
    swpPrint(fout);

    fprintf(fout, "\e[34;1mtesting swpPeek and swpRemove\e[0m\n");
    fprintf(fout, "\n");
    SwappedProcess *p = swpPeek(1);
    fprintf(stdout, "pid: %u, profile.count: %u\n", p->pid, p->profile.segmentCount);
    swpRemove(1);
    swpPrint(fout);

    fprintf(fout, "\e[34;1mtesting pctInsert and pctPrint\e[0m\n");
    for (uint32_t i = 0; i < 3; i++)
    {
        ForthcomingProcess *p = &forthcomingTable.process[i];
        pctInsert(p->pid, p->arrivalTime, p->lifetime, &p->addressSpace);
    }
    pctPrint(fout);

    fprintf(fout, "\e[34;1mtesting pctGetters\e[0m\n");
    fprintf(fout, "\n");
    for (uint32_t i = 0; i < 3; i++)
    {
        ForthcomingProcess *p = &forthcomingTable.process[i];
        uint32_t lifetime = pctGetLifetime(p->pid);
        const char *st = pctGetStateAsString(p->pid);
        fprintf(stdout, "-- [%u]: lifetime: %u; state: %s\n", p->pid, lifetime, st);
    }
    fprintf(fout, "\n");

    fprintf(fout, "\e[34;1mtesting pctUpdateState\e[0m\n");
    fprintf(fout, "\n");
    ForthcomingProcess *p1 = &forthcomingTable.process[0];
    pctUpdateState(p1->pid, DISCARDED);
    p1 = &forthcomingTable.process[1];
    AddressSpaceMapping mp = {2, {0x300, 0x200, 0, 0}};
    pctUpdateState(p1->pid, ACTIVE, 125, &mp);
    p1 = &forthcomingTable.process[2];
    pctUpdateState(p1->pid, SWAPPED);
    pctPrint(fout);

    fprintf(fout, "\e[34;1mtesting pctUpdateState\e[0m\n");
    fprintf(fout, "\n");
    p1 = &forthcomingTable.process[1];
    pctUpdateState(p1->pid, FINISHED, 425);
    pctPrint(fout);
    
    fprintf(fout, "\e[34;1mtesting memFirstFitAlloc\e[0m\n");
    fprintf(fout, "\n");
    fprintf(fout, "memFreeHead: %p; memOccupiedHead: %p\n", memFreeHead, memOccupiedHead);
    MemBlock *p2 = &memFreeHead->block;
    fprintf(fout, "memFreeHead: (pid: %u, size: 0x%x, address: 0x%x)\n", p2->pid, p2->size, p2->address);
    fprintf(fout, "\n");
    Address add = memFirstFitAlloc(111, 0x200);
    MemBlock *p3 = &memOccupiedHead->block;
    fprintf(fout, "address: %x\n", add);
    fprintf(fout, "memFreeHead: %p; memOccupiedHead: %p\n", memFreeHead, memOccupiedHead);
    fprintf(fout, "memFreeHead: (pid: %u, size: 0x%x, address: 0x%x)\n", p2->pid, p2->size, p2->address);
    fprintf(fout, "memFreeHead: (pid: %u, size: 0x%x, address: 0x%x)\n", p3->pid, p3->size, p3->address);
    
    fprintf(fout, "\n");
    fprintf(fout, "\e[34;1mtesting memFirstFitAlloc\e[0m\n");
    fprintf(fout, "\n");
    memFirstFitFree(add);
    fprintf(fout, "memFreeHead: %p; memOccupiedHead: %p\n", memFreeHead, memOccupiedHead);
    p2 = &memFreeHead->block;
    fprintf(fout, "memFreeHead: (pid: %u, size: 0x%x, address: 0x%x)\n", p2->pid, p2->size, p2->address);
    fprintf(fout, "\n");
    
}

