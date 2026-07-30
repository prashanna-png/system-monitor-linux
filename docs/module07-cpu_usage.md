# Module 7 - CPU Usage Display

## Goal

Display the current CPU usage percentage of the Linux system.

Equivalent terminal command:

```bash
top
```

or

```bash
mpstat
```

---

## Linux APIs Used

```c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
```

Uses:

- `fopen()`
- `fgets()`
- `sscanf()`
- `fclose()`
- `sleep()`

---

## Important Concepts

### `/proc/stat`

`/proc/stat` is a virtual file provided by the Linux kernel.

The first line contains CPU statistics accumulated since the system booted.

Example:

```text
cpu  669674 2537 184580 16399157 9210 0 9510 0 0 0
```

---

### CPU Time Fields

The following CPU counters are used:

- `user`
- `nice`
- `system`
- `idle`
- `iowait`
- `irq`
- `softirq`

These values continuously increase while the system is running.

---

### Why Two Readings?

Since the values in `/proc/stat` are cumulative, a single reading cannot determine CPU usage.

The program:

- Reads the CPU counters.
- Waits for **1 second**.
- Reads the CPU counters again.
- Calculates the difference between the two readings.

---

## Algorithm

```text
Read CPU statistics

↓

Store first CPU counters

↓

Wait for 1 second

↓

Read CPU statistics again

↓

Calculate Total CPU Time

↓

Calculate Idle Time

↓

Compute CPU Usage Percentage

↓

Display CPU Usage
```

---

## CPU Usage Formula

```text
Total CPU Time =
user + nice + system + idle + iowait + irq + softirq

Idle Time =
idle + iowait

CPU Usage (%) =
((Total Difference − Idle Difference) / Total Difference) × 100
```

---

## Output

```text
==================================
        CPU Usage
==================================
CPU Usage : 2.65%
```

---

## Concepts Learned

- Virtual filesystem (`/proc`)
- Reading CPU statistics from `/proc/stat`
- Parsing data using `sscanf()`
- Using `sleep()` for interval-based monitoring
- Calculating CPU usage using two snapshots
- Understanding cumulative CPU counters

---

## Files

```text
include/
    cpu.h

src/
    cpu.c
```
