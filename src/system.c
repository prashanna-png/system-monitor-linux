#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

static void printHostname(void)
{
  char hostname[256];
  if (gethostname(hostname, sizeof(hostname)) == 0)
  {
    // terminal command = "hostname"
    printf("Hostname : %s\n", hostname);
  }
  else
  {
    printf("Failed to retrieve hostname.\n");
  }
}

static void printUser(void)
{
  // terminal command = "whoami"
  __uid_t uid = getuid();

  printf("Userid: %d\n", uid);

  struct passwd *pw = getpwuid(uid);

  if (pw != NULL)
  {
    printf("Username : %s\n", pw->pw_name);
  }
  else
  {
    printf("failed to retrieve username");
  }
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