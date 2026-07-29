#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>
#include <unistd.h>

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

char line[200];
char label[10];
long user, nice_val, system, idle, iowait, irq, softiq;

static void readCPUStatus(void)
{
  FILE *fp = fopen("/proc/stat", "r");

  if (fp == NULL)
  {
    printf("Unable to open File\n");
    return;
  }

  if (fgets(line, sizeof(line), fp))
  {
    int matched = sscanf(line, "%s %ld %ld %ld %ld %ld %ld %ld",
                         label, &user, &nice_val, &system, &idle, &iowait, &irq, &softiq);

    if (matched == 8)
    {
      printf("label: %s \n user: %ld\n nice: %ld\n system: %ld\n idle: %ld\n iowait: %ld\n irq: %ld\n softiq: %ld\n",
             label, user, nice_val, system, idle, iowait, irq, softiq);
    }
    else
    {
      printf("Failed to parse CPU stats line\n");
    }
  }
  fclose(fp);
}

static void calculateCPUUsage(void)
{
  readCPUStatus();
  sleep(1);
  readCPUStatus();
}

void printCPUInfo(void)
{
  printModelName();
  printArchitecture();
  printCoreCount();
  printThreadCount();
}
void printCPUUsage(void)
{
  calculateCPUUsage();
}