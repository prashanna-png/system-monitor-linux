#include <stdio.h>
#include <string.h>

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
      printf("Model Name: %s", start+2);
      break;
    }
  }
}

static void printArchitecture(void)
{
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