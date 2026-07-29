#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

static void printRunningProcesses(void)
{
  DIR *dir = opendir("/proc");
  struct dirent *entry;

  int processCount = 0;

  while ((entry = readdir(dir)) != NULL)
  {
    if (isdigit(entry->d_name[0]))
    {
      processCount++;
    }
  }
  printf("Running Processes\t:%d\n", processCount);

  closedir(dir);
}

void printProcessInfo(void)
{
  printRunningProcesses();
}