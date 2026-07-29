#include<sys/statvfs.h>

static void printDiskStats(void)
{
  struct statvfs disk;
  
}

void printDiskInfo(void)
{
  printDiskStats();
}