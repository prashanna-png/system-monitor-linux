#include <stdio.h>
#include <string.h>

static void printMemoryStats(void)
{
  FILE *fp = fopen("/proc/meminfo", "r");

  char line[200];
  char target1[] = "MemTotal:";
  char target2[] = "MemAvailable:";
  double totalGB;
  double availableGB;
  double usedMemory;

  if (fp == NULL)
  {
    printf("unable to open file\n");
    return;
  }
  while (fgets(line, sizeof(line), fp))
  {
    if (strncmp(target1, line, strlen(target1)) == 0)
    {
      int totalMem;
      char *start = strrchr(line, ':');
      sscanf(start + 1, "%d", &totalMem);

      totalGB = totalMem / (1024.0 * 1024.0);
      printf("Total RAM\t: %.2f GB\n", totalGB);
    }
    if (strncmp(target2, line, strlen(target2)) == 0)
    {
      int totalAvailable;
      char *start = strrchr(line, ':');
      sscanf(start + 1, "%d", &totalAvailable);

      availableGB = totalAvailable / (1024.0 * 1024.0);
      printf("Available\t: %.2f GB\n", availableGB);
    }
  }

  usedMemory = totalGB - availableGB;
  printf("Used\t\t: %.2f GB\n", usedMemory);
  fclose(fp);
}

void printMemoryInfo(void)
{
  printMemoryStats();
}