#include "system.h"
#include "cpu.h"
#include "memory.h"
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

  printf("==================================\n");
  printf("\tMemory Information\n");
  printf("==================================\n");
  printMemoryInfo();

  return 0;
}