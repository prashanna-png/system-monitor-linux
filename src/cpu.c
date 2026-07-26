#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>

static void printModelName(void)
{
  FILE *fp;
  fp = fopen("/proc/cpuinfo", "r");

  char modelName[200];
  char target[] = "model name	:";
  if (fp == NULL)
  {
    printf("unable to open file");
  }

  while (fgets(modelName, 200, fp))
  {
    if (strncmp(target, modelName, 12) == 0)
    {
      char *start = strchr(modelName, ':');
      printf("Model Name\t: %s", start + 2);
      break;
    }
  }
}

static void printArchitecture(void)
{
  struct utsname uts;
  if (uname(&uts) == 0)
  {
    printf("Architecture\t: %s\n", uts.machine);
  }
}

static void printCoreCount(void)
{
}

static void printThreadCount(void)
{
}

void printCPUInfo(void)
{
  printModelName();
  printArchitecture();
  printCoreCount();
  printThreadCount();
}