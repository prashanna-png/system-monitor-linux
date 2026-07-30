#include <sys/statvfs.h>
#include <stdio.h>

static void printDiskStats(void)
{
  struct statvfs disk;
  if (statvfs("/", &disk) == 0)
  {
    unsigned long long totalByte = disk.f_blocks * disk.f_frsize;
    double totalGB = totalByte / (1024.0 * 1024.0 * 1024.0);
    unsigned long long freeByte = disk.f_bavail * disk.f_frsize;
    double freeGB = freeByte / (1024.0 * 1024.0 * 1024.0);
    unsigned long long usedByte = totalByte - freeByte;
    double usedGB = usedByte / (1024.0 * 1024.0 * 1024.0);
    double usedPercentage =
        (double)usedByte / totalByte * 100;

    printf("Total Space\t\t: %.2f GB\n", totalGB);

    printf("Free Space\t\t: %.2f GB\n", freeGB);

    printf("Used Space\t\t: %.2f GB\n", usedGB);

    printf("Usage\t\t\t: %.2f%%\n", usedPercentage);
  }
  else
  {
    printf("Failed to retrieve Disk Information\n");
    return;
  }
}

void printDiskInfo(void)
{
  printDiskStats();
}