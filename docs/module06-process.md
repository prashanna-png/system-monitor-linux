# Module 6 - Process Information

## Goal

Display the total number of currently running processes.

Equivalent terminal command:

```bash
ps -e
```

or

```bash
ls /proc
```

---

## Linux API Used

```c
#include <dirent.h>
#include <ctype.h>
```

Uses:

- `opendir()`
- `readdir()`
- `closedir()`
- `isdigit()`

---

## Important Concepts

### `/proc`

`/proc` is a virtual filesystem created by the Linux kernel.

It contains:

- **Process directories** (named using Process IDs)
- **System information files**

Example:

```text
/proc
├── 1
├── 2
├── 345
├── cpuinfo
├── meminfo
├── uptime
└── version
```

---

### Process Directories

Directories with **numeric names** represent running processes.

Example:

```text
1
2
345
786
```

Each number is called a **Process ID (PID)**.

Every running process has its own directory inside `/proc`.

---

### System Information Files

Entries such as:

```text
cpuinfo
meminfo
uptime
version
```

are **not processes**.

They provide information about the entire system.

---

## Algorithm

```text
Open /proc directory

↓

Read each directory entry

↓

Check whether the first character is a digit

↓

If yes, count it as a process

↓

Repeat until the end of the directory

↓

Close the directory

↓

Display the total number of running processes
```

---

## Output

```text
==================================
      Process Information
==================================
Running Processes : 312
```

---

## Concepts Learned

- Virtual filesystem (`/proc`)
- Process IDs (PID)
- Directory handling in C
- `opendir()`
- `readdir()`
- `closedir()`
- Character checking using `isdigit()`

---

## Files

```text
include/
    process.h

src/
    process.c
```
