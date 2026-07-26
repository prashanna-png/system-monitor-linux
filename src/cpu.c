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
    printf("unable to open file\n");
    return;
  }

  while (fgets(modelName, 200, fp))
  {
    if (strncmp(target, modelName, strlen(target)) == 0)
    {
      char *start = strchr(modelName, ':');
      printf("Model Name\t: %s", start + 2);
      break;
    }
  }
  fclose(fp);
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
  FILE *fp;
  fp = fopen("/proc/cpuinfo", "r");

  char cpuCore[200];
  char target[] = "cpu cores	:";
  if (fp == NULL)
  {
    printf("unable to open file\n");
    return;
  }

  while (fgets(cpuCore, 200, fp))
  {
    if (strncmp(target, cpuCore, strlen(target)) == 0)
    {
      char *start = strchr(cpuCore, ':');
      printf("Cores\t\t: %s", start + 2);
      break;
    }
  }
  fclose(fp);
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