#include <stdio.h>

static double Uptime = 0.0;

static void printTime(void)
{
  FILE *fp = fopen("/proc/uptime", "r");
  char line[200];
  if (fp == NULL)
  {
    printf("unable to open file\n");
    return;
  }
  if (fgets(line, sizeof(line), fp))
  {
    if (sscanf(line, "%lf", &Uptime) == 1)
      printf("%.0f\n", Uptime);
    else
      printf("failed to parse uptime\n");
  }
  fclose(fp);
}

void printUpTime(void)
{
  printTime();
}