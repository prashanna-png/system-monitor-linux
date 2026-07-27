#include "system.h"
#include "cpu.h"
#include "memory.h"
#include "uptime.h"
#include <stdio.h>

int main(void)
{
  printf("==================================\n");
  printf("\tSystem Information\n");
  printf("==================================\n");
  printSystemInfo();

  printf("\n==================================\n");
  printf("\tCPU Information\n");
  printf("==================================\n");
  printCPUInfo();

  printf("\n==================================\n");
  printf("\tMemory Information\n");
  printf("==================================\n");
  printMemoryInfo();

  printf("\n==================================\n");
  printf("\tUp Time\n");
  printf("==================================\n");
  printUpTime();

  return 0;
}