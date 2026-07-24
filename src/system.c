#include <stdio.h>
#include <unistd.h>

static void printHostname(void)
{
  char hostname[512];
  if (gethostname(hostname, sizeof(hostname)) == 0) {
    printf("Hostname: %s\n", hostname);
  } else {
    perror("gethostname");
  }
}

static void printUser(void)
{
  // Code to print username
}

static void printKernel(void)
{
  // Code to print kernel version
}

static void printOS(void)
{
  // Code to print OS
}

void printSystemInfo(void)
{
  printHostname();
  printUser();
  printKernel();
  printOS();
}