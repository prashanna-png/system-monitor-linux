# Module 8 - Memory Usage Display

## Goal

Display the current memory usage percentage of the Linux system.

Equivalent terminal command:

```bash
free
```

or

```bash
free -h
```

---

## Linux APIs Used

```c
#include <stdio.h>
#include <string.h>
```

Uses:

- `fopen()`
- `fgets()`
- `strncmp()`
- `sscanf()`
- `fclose()`

---

## Important Concepts

### `/proc/meminfo`

`/proc/meminfo` is a virtual file provided by the Linux kernel.

It contains detailed information about the system's memory usage.

Example:

```text
MemTotal:       16090460 kB
MemAvailable:   10953248 kB
```

---

### Memory Fields Used

The program uses the following memory counters:

- `MemTotal` – Total physical RAM installed.
- `MemAvailable` – Memory currently available for new applications.

---

### Memory Usage Calculation

The amount of used memory is calculated by subtracting the available memory from the total memory.

Formula:

```text
Used Memory = MemTotal − MemAvailable
```

The memory usage percentage is then calculated as:

```text
Memory Usage (%) =
((MemTotal − MemAvailable) / MemTotal) × 100
```

---

## Algorithm

```text
Open /proc/meminfo

↓

Read MemTotal

↓

Read MemAvailable

↓

Calculate Used Memory

↓

Calculate Memory Usage Percentage

↓

Display Memory Usage

↓

Close the file
```

---

## Output

```text
==================================
        Memory Usage
==================================
Memory Usage : 31.86%
```

---

## Concepts Learned

- Reading memory information from `/proc/meminfo`
- Parsing values using `sscanf()`
- Calculating used memory
- Computing memory usage percentage
- Understanding Linux memory statistics

---

## Files

```text
include/
    memory.h

src/
    memory.c
```
