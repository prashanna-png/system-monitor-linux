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
    printf("Hostname\t: %s\n", hostname);
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

  printf("Userid\t\t: %d\n", uid);

  struct passwd *pw = getpwuid(uid);

  if (pw != NULL)
  {
    printf("Username\t: %s\n", pw->pw_name);
  }
  else
  {
    printf("Failed to retrieve username\n");
    return;
  }
}

// terminal command: "uname" or "uname -r"
static void printKernel(void)
{
  struct utsname uts;
  if (uname(&uts) == 0)
  {
    printf("Kernel\t\t: %s \n", uts.release);
  }
  else
  {
    printf("Failed to retrieve kernel version\n");
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
    printf("Unable to open file\n");
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
        printf("OS\t\t: %s\n", start + 1);
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