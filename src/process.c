#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

static void printRunningProcesses(void)
{
  DIR *dir = opendir("/proc");
  struct dirent *entry;

  int processCount = 0;

  if (dir == NULL)
  {
    printf("Unable to open /proc\n");
    return;
  }

  while ((entry = readdir(dir)) != NULL)
  {
    if (isdigit(entry->d_name[0]))
    {
      processCount++;
    }
  }
  printf("Running Processes\t: %d\n", processCount);

  closedir(dir);
}

void printProcessInfo(void)
{
  printRunningProcesses();
}