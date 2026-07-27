#include <stdio.h>
#include <string.h>

static void printTotalMemory(void)
{
  FILE *fp = fopen("/proc/meminfo", "r");

  char line[200];
  char target[] = "MemTotal:";
  if (fp == NULL)
  {
    printf("unable to open file\n");
    return;
  }
  while (fgets(line, sizeof(line), fp))
  {
    if (strncmp(target, line, strlen(target)) == 0)
    {
      int totalMem;
      char *start = strrchr(line, ':');
      sscanf(start + 1, "%d", &totalMem);

      double totalGB = totalMem / (1024.0 * 1024.0);
      printf("Total RAM\t:%.2f GB\n", totalGB);
    }
  }
  fclose(fp);
}
static void printAvailableMemory(void)
{

  FILE *fp = fopen("/proc/meminfo", "r");

  char line[200];
  char target[] = "MemAvailable:";
  if (fp == NULL)
  {
    printf("unable to open file\n");
    return;
  }
  while (fgets(line, sizeof(line), fp))
  {
    if (strncmp(target, line, strlen(target)) == 0)
    {
      int totalAvailable;
      char *start = strrchr(line, ':');
      sscanf(start + 1, "%d", &totalAvailable);

      double totalGB = totalAvailable / (1024.0 * 1024.0);
      printf("Available\t:%.2f GB\n", totalGB);
    }
  }
  fclose(fp);
}
static void printUsedMemory(void)
{
  
}

void printMemoryInfo(void)
{
  printTotalMemory();
  printAvailableMemory();
  printUsedMemory();
}