#include <stdio.h>
#include <unistd.h>

static void printHostname(void)
{
  char hostname[256];
  if (gethostname(hostname, sizeof(hostname)) == 0)
  {
    printf("Hostname : %s\n", hostname);
  }
  else
  {
    printf("Failed to retrieve hostname.\n");
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