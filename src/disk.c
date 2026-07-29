#include <sys/statvfs.h>
#include <stdio.h>

static void printDiskStats(void)
{
  struct statvfs disk;
  if (statvfs("/", &disk) == 0)
  {
    printf("Total block\t\t:%ld\n", disk.f_blocks);
    printf("Total block size\t:%ld\n", disk.f_frsize);
    long int totalSize = disk.f_blocks * disk.f_frsize;

    double totalGB = totalSize / (1024.0 * 1024.0 * 1024.0);

    printf("total size\t\t: %.2f GB\n", totalGB);
  }
  else
  {
  }
}

void printDiskInfo(void)
{
  printDiskStats();
}