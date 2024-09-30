#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "delays.h"
#include "process.h"

int main(void)
{
  pid_t ret = pfork();
  int i;
  if (ret == 0)
  {
    i = 1;
    while(i<11){
            printf("%d\n",i);
            i++;
    }
  }
  else
  {
    i = 11;
    pwait(NULL);
    while(i<21){
            printf("%d\n",i);
            i++;
    }
  }

  return EXIT_SUCCESS;
}