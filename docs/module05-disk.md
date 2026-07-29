# Module 5 - Disk Information

## Goal

Display:

- Total Disk Space
- Free Disk Space
- Used Disk Space
- Disk Usage Percentage

Equivalent terminal command:

```bash
df -h
```

---

## Linux API Used

```c
#include <sys/statvfs.h>
```

Uses:

- `statvfs()`
- `struct statvfs`

---

## Important Structure Members

| Member     | Description                           |
| ---------- | ------------------------------------- |
| `f_blocks` | Total number of filesystem blocks     |
| `f_frsize` | Size of each block (bytes)            |
| `f_bavail` | Free blocks available to normal users |

---

## Calculations

**Total Space**

```text
Total = f_blocks × f_frsize
```

**Free Space**

```text
Free = f_bavail × f_frsize
```

**Used Space**

```text
Used = Total − Free
```

**Usage**

```text
Usage (%) = (Used / Total) × 100
```

All byte values are converted to GB before displaying.

---

## Output

```text
==================================
        Disk Information
==================================
Total Space     : 293.79 GB
Free Space      : 152.67 GB
Used Space      : 141.12 GB
Usage           : 48.03%
```

---

## Concepts Learned

- `statvfs()` system call
- `struct statvfs`
- Filesystem blocks
- Byte to GB conversion
- Disk usage calculation

---

## Files

```text
include/
    disk.h

src/
    disk.c
```
