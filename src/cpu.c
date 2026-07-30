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
long before_user, before_nice_val, before_system, before_idle, before_iowait, before_irq, before_softiq;

long after_user, after_nice_val, after_system, after_idle, after_iowait, after_irq, after_softiq;

long user, nice_val, system, idle, iowait, irq, softiq;

static void readCPUStatus(int isFirst)
{
  FILE *fp = fopen("/proc/stat", "r");

  if (fp == NULL)
  {
    printf("Unable to open File\n");
    return;
  }

  if (fgets(line, sizeof(line), fp))
  {
    sscanf(line, "%s %ld %ld %ld %ld %ld %ld %ld",
           label, &user, &nice_val, &system, &idle, &iowait, &irq, &softiq);

    if (isFirst == 1)
    {
      before_user = user;
      before_nice_val = nice_val;
      before_system = system;
      before_idle = idle;
      before_iowait = iowait;
      before_irq = irq;
      before_softiq = softiq;
    }
    else if (isFirst == 0)
    {
      after_user = user;
      after_nice_val = nice_val;
      after_system = system;
      after_idle = idle;
      after_iowait = iowait;
      after_irq = irq;
      after_softiq = softiq;
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
  readCPUStatus(1);
  sleep(1);
  readCPUStatus(0);

  long totalBefore = before_user + before_nice_val + before_system + before_idle + before_iowait + before_irq + before_softiq;

  long totalAfter = after_user + after_nice_val + after_system + after_idle + after_iowait + after_irq + after_softiq;

  long idleBefore = before_idle + before_iowait;
  long idleAfter = after_idle + after_iowait;

  long totalDiff = totalAfter - totalBefore;
  long idleDiff = idleAfter - idleBefore;

  double cpu_usage = ((totalDiff - idleDiff) * 100.0) / totalDiff;
  printf("CPU Usage: %.2f%%\n", cpu_usage);
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