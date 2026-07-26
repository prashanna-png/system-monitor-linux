#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>

static void printModelName(void)
{
  FILE *fp = fopen("/proc/cpuinfo", "r");

  char line[200];
  char target[] = "model name	:";
  if (fp == NULL)
  {
    printf("unable to open file\n");
    return;
  }

  while (fgets(line, 200, fp))
  {
    if (strncmp(target, line, strlen(target)) == 0)
    {
      char *start = strchr(line, ':');
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
  FILE *fp = fopen("/proc/cpuinfo", "r");

  char line[200];
  char target[] = "cpu cores	:";
  if (fp == NULL)
  {
    printf("unable to open file\n");
    return;
  }

  while (fgets(line, 200, fp))
  {
    if (strncmp(target, line, strlen(target)) == 0)
    {
      char *start = strchr(line, ':');
      printf("Cores\t\t: %s", start + 2);
      break;
    }
  }
  fclose(fp);
}

static void printThreadCount(void)
{
  FILE *fp = fopen("/proc/cpuinfo", "r");

  char line[200];
  char target[] = "siblings	:";
  if (fp == NULL)
  {
    printf("unable to open file\n");
    return;
  }

  while (fgets(line, 200, fp))
  {
    if (strncmp(target, line, strlen(target)) == 0)
    {
      char *start = strchr(line, ':');
      printf("threads\t\t: %s", start + 2);
      break;
    }
  }
  fclose(fp);
}

void printCPUInfo(void)
{
  printModelName();
  printArchitecture();
  printCoreCount();
  printThreadCount();
}