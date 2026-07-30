#include "system.h"
#include "cpu.h"
#include "memory.h"
#include "uptime.h"
#include "disk.h"
#include "process.h"
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
  printf("\t\tUp Time\n");
  printf("==================================\n");
  printUpTime();

  printf("\n==================================\n");
  printf("\tDisk Information\n");
  printf("==================================\n");
  printDiskInfo();

  printf("\n==================================\n");
  printf("\tProcess Information\n");
  printf("==================================\n");
  printProcessInfo();

  printf("\n==================================\n");
  printf("\t CPU Usage\n");
  printf("==================================\n");
  printCPUUsage();

  printf("\n==================================\n");
  printf("\t Memory Usage\n");
  printf("==================================\n");
  printMemoryUsage();

  return 0;
}