#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/utsname.h>
#include <string.h>

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
    return;
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
    return;
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
    return;
  }
}

// terminal command: "cat /etc/os-release"
static void printOS(void)
{
  FILE *fp = fopen("/etc/os-release", "r");

  char target[] = "PRETTY_NAME=";

  if (fp == NULL)
  {
    printf("Unable to open file");
    return;
  }

  char line[200];
  while (fgets(line, 100, fp))
  {
    if (strncmp(target, line, strlen(target)) == 0)
    {
      char *start = strchr(line, '"');
      char *end = strrchr(line, '"');
      if (start != NULL && end != NULL && start != end)
      {
        *end = '\0';
        printf("OS         : %s\n", start + 1);
        break;
      }
    }
  }
  fclose(fp);
}

void printSystemInfo(void)
{
  printHostname();
  printUser();
  printKernel();
  printOS();
}