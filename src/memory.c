#include <stdio.h>
#include <string.h>

double totalGB;
double usedMemory;

static void printMemoryStats(void)
{
  FILE *fp = fopen("/proc/meminfo", "r");

  char line[200];
  char target1[] = "MemTotal:";
  char target2[] = "MemAvailable:";
  double availableGB;

  long totalMem = 0;
  long totalAvailable = 0;

  if (fp == NULL)
  {
    printf("unable to open file\n");
    return;
  }
  while (fgets(line, sizeof(line), fp))
  {
    if (strncmp(target1, line, strlen(target1)) == 0)
    {
      char *start = strrchr(line, ':');
      sscanf(start + 1, "%li", &totalMem);

      totalGB = totalMem / (1024.0 * 1024.0);
      printf("Total RAM\t: %.2f GB\n", totalGB);
    }
    if (strncmp(target2, line, strlen(target2)) == 0)
    {
      char *start = strrchr(line, ':');
      sscanf(start + 1, "%li", &totalAvailable);

      availableGB = totalAvailable / (1024.0 * 1024.0);
      printf("Available\t: %.2f GB\n", availableGB);
    }
  }

  usedMemory = totalGB - availableGB;
  printf("Used\t\t: %.2f GB\n", usedMemory);
  fclose(fp);
}

static void calculateMemoryUsage()
{
  double memoryUsage = (usedMemory / totalGB) * 100;
  printf("memory Usage: %.2f%%\n", memoryUsage);
}

void printMemoryInfo(void)
{
  printMemoryStats();
}
void printMemoryUsage(void)
{
  calculateMemoryUsage();
}