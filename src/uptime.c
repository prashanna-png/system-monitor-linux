#include <stdio.h>
#include <math.h>

double uptimeSeconds = 0.0;

static void printTime(void)
{
  FILE *fp = fopen("/proc/uptime", "r");
  char line[200];
  long days;
  long hours;
  long minutes;

  if (fp == NULL)
  {
    printf("Unable to open file\n");
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

      if (days > 0)
      {
        printf("Uptime : %ld days %ld hours %ld minutes %ld seconds\n",
               days, hours, minutes, seconds);
      }
      else if (hours > 0)
      {
        printf("Uptime : %ld hours %ld minutes %ld seconds\n",
               hours, minutes, seconds);
      }
      else
      {
        printf("Uptime : %ld minutes %ld seconds\n",
               minutes, seconds);
      }
    }
    else
      printf("Failed to parse uptime\n");
  }
  fclose(fp);
}

void printUpTime(void)
{
  printTime();
}