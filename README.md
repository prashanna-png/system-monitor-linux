# Linux System Monitor

A lightweight Linux System Monitor written in **C** that retrieves and displays real-time system information by reading Linux virtual system files under the **/proc** filesystem and using Linux system APIs.

The project was developed as a learning project to understand Linux system programming, file handling, directory handling, and kernel-provided system information.

---

## Motivation

I wanted to go beyond just using tools like `htop` or `neofetch` and actually understand how they work under the hood — how Linux exposes system information through the `/proc` filesystem and system calls, and how that data can be parsed and presented from scratch in C.

---

## Features

- System Information
  - Hostname
  - User ID (UID)
  - Username
  - Kernel Version
  - Operating System

- CPU Information
  - Processor Model
  - Architecture
  - Number of CPU Cores
  - Number of Threads

- Memory Information
  - Total RAM
  - Available RAM
  - Used RAM

- Uptime
  - System uptime displayed in:
    - Days
    - Hours
    - Minutes
    - Seconds

- Disk Information
  - Total Disk Space
  - Free Disk Space
  - Used Disk Space
  - Disk Usage Percentage

- Process Information
  - Total Running Processes

- CPU Usage
  - Current CPU Usage Percentage

- Memory Usage
  - Current Memory Usage Percentage

---

## Project Structure

```text
linux-system-monitor/
│
├── include/
│   ├── cpu.h
│   ├── disk.h
│   ├── memory.h
│   ├── process.h
│   ├── system.h
│   └── uptime.h
│
├── src/
│   ├── main.c
│   ├── cpu.c
│   ├── disk.c
│   ├── memory.c
│   ├── process.c
│   ├── system.c
│   └── uptime.c
│
├── build/
│
├── Makefile
│
└── README.md
```

---

## Modules

| Module              | Source File | Description                                   |
| ------------------- | ----------- | --------------------------------------------- |
| System Information  | `system.c`  | Hostname, UID, username, kernel version, OS   |
| CPU Information     | `cpu.c`     | Processor model, architecture, cores, threads |
| Memory Information  | `memory.c`  | Total, available, and used RAM                |
| Uptime              | `uptime.c`  | System uptime in days/hours/minutes/seconds   |
| Disk Information    | `disk.c`    | Total, free, and used disk space              |
| Process Information | `process.c` | Count of running processes                    |
| CPU Usage           | `cpu.c`     | Real-time CPU usage percentage                |
| Memory Usage        | `memory.c`  | Real-time memory usage percentage             |

---

## Linux Files Used

The project gathers system information from the Linux virtual filesystem.

| File            | Purpose                 |
| --------------- | ----------------------- |
| `/proc/cpuinfo` | CPU information         |
| `/proc/meminfo` | Memory information      |
| `/proc/uptime`  | System uptime           |
| `/proc/stat`    | CPU usage statistics    |
| `/proc/`        | Running processes       |
| `statvfs()`     | Disk information        |
| `uname()`       | Kernel and architecture |
| `gethostname()` | Hostname                |
| `getuid()`      | User ID                 |
| `getpwuid()`    | Username                |

---

## Technologies Used

- C Programming Language
- GCC Compiler
- Makefile
- Linux System APIs
- Linux Virtual File System (/proc)

---

## Compilation

Compile the project using:

```bash
make
```

Run the program:

```bash
./build/system-monitor
```

Clean build files:

```bash
make clean
```

---

## Sample Output

```text
==================================
        System Information
==================================
Hostname        : prashanna-LOQ
Userid          : 1000
Username        : prashanna
Kernel          : 7.0.0-28-generic
OS              : Ubuntu 24.04.4 LTS
==================================
        CPU Information
==================================
Model Name      : 13th Gen Intel(R) Core(TM) i5-13500H
Architecture    : x86_64
Cores           : 12
threads         : 16
==================================
        Memory Information
==================================
Total RAM       : 15.34 GB
Available       : 10.45 GB
Used            : 4.89 GB
==================================
                Up Time
==================================
Uptime : 18 minutes 22 seconds
==================================
        Disk Information
==================================
Total Space             : 293.79 GB
Free Space              : 152.50 GB
Used Space              : 141.29 GB
Usage                   : 48.09%
==================================
        Process Information
==================================
Running Processes       :406
==================================
         CPU Usage
==================================
CPU Usage: 5.47%
==================================
         memory Usage
==================================
memory Usage: 31.86%
```

---

## Known Limitations

- Disk information reflects only the root (`/`) partition, not other mounted disks or partitions.
- CPU usage requires a blocking 1-second sample window (two `/proc/stat` reads a second apart) to calculate an accurate delta, so the program takes at least ~1 second to run.
- Process count includes all numeric entries under `/proc`, which counts threads/processes as the kernel exposes them, not a filtered "user-facing process" list like `ps aux` shows.
- No continuous/live refresh mode yet — each run is a single snapshot.

---

## Learning Outcomes

Through this project, I learned:

- Linux System Programming
- Reading data from the `/proc` virtual filesystem
- Using Linux APIs (`uname()`, `statvfs()`, `getuid()`, etc.)
- File handling in C
- Directory handling using `opendir()` and `readdir()`
- Parsing system files using `sscanf()`
- Calculating CPU and memory usage
- Writing modular C programs
- Organizing projects using header files and source files
- Building projects with Makefiles

---

## Requirements

- Ubuntu / Linux
- GCC Compiler
- GNU Make

---

## Author

**Prashanna** ([@prashanna-png](https://github.com/prashanna-png))
