#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/utsname.h>

// terminal command = "hostname"
static void printHostname(void)
{
  char hostname[256];
  if (gethostname(hostname, sizeof(hostname)) == 0)
  {
    printf("Hostname   : %s\n", hostname);
  }
  else
  {
    printf("Failed to retrieve hostname.\n");
  }
}

// terminal command = "whoami"
static void printUser(void)
{
  __uid_t uid = getuid();

  printf("Userid     : %d\n", uid);

  struct passwd *pw = getpwuid(uid);

  if (pw != NULL)
  {
    printf("Username   : %s\n", pw->pw_name);
  }
  else
  {
    printf("failed to retrieve username");
  }
}

// terminal command: "name" or "name -r"
static void printKernel(void)
{
  struct utsname uts;
  if (uname(&uts) == 0)
  {
    printf("Kernel     : %s \n", uts.release);
  }
  else
  {
    printf("failed to retrieve kernel version");
  }
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