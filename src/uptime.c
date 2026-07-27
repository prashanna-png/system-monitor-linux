#include <stdio.h>
#include <math.h>

static double uptimeSeconds = 0.0;

static void printTime(void)
{
  FILE *fp = fopen("/proc/uptime", "r");
  char line[200];
  int days;
  int hours;
  int minutes;

  if (fp == NULL)
  {
    printf("unable to open file\n");
    return;
  }
  if (fgets(line, sizeof(line), fp))
  {
    if (sscanf(line, "%lf", &uptimeSeconds) == 1)
    {
      long seconds = (long)uptimeSeconds;
      days = seconds / 86400;

      seconds %= 86400;

      hours = seconds / 3600;

      seconds %= 3600;

      minutes = seconds / 60;

      seconds %= 60;

      printf("Up time\t:%d Days %d hours %d minutes %ld seconds\n", days, hours, minutes, seconds);
    }
    else
      printf("failed to parse uptime\n");
  }
  fclose(fp);
}

void printUpTime(void)
{
  printTime();
}