# Installation

## Clone the repository

```bash
git clone https://github.com/prashanna-png/linux-system-monitor.git
cd linux-system-monitor
```

## Build the project

```bash
make
```

## Run

```bash
./build/system-monitor
```

## Clean build files

```bash
make clean
```

## Compatibility

This project is designed for Linux systems and has been tested on Ubuntu 24.04 LTS.

It uses standard Linux interfaces such as:

- `/proc`
- `/etc/os-release`
- `statvfs()`
- `uname()`
- POSIX system calls

Therefore, it should work on most modern Linux distributions with little or no modification.
