#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "delays.h"
#include "process.h"

int main(void)
{
  for(int i = 0;i < 40; i++){
    printf("=");
  }
    printf("\n");

  pid_t ret = pfork();
  
  if (ret == 0)
  {
    execl("/bin/ls", "ls", "-l", NULL);
    return EXIT_FAILURE;
  }
  else
  {
    pwait(NULL);
    for(int j = 0;j < 40; j++){
        printf("=");
    }

    printf("\n");

  }

  return EXIT_SUCCESS;
}