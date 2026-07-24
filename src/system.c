#include <stdio.h>

static void printHostname(void)
{
  char hostname[500];
  if (gethostname(hostname, sizeof(hostname)) == 0)
  {
    printf("hostname:", hostname);
  }
  else
  {
    printf("error");
  }
}

static void printUser(void)
{
}

static void printKernel(void)
{
}

static void printOS(void)
{
}

void printSystemInfo(void)
{
  printHostname();
  printUser();
  printKernel();
  printOS();
}