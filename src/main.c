#include "system.h"
#include "cpu.h"
#include <stdio.h>

int main(void)
{
  printf("==================================\n");
  printf("\tSystem Information\n");
  printf("==================================\n");
  printSystemInfo();

  printf("==================================\n");
  printf("\tCPU Information\n");
  printf("==================================\n");
  printCPUInfo();

  return 0;
}