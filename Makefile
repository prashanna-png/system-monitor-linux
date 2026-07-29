CC = gcc #compiler

CFLAGS = -Wall -Wextra -Iinclude  #search header inside include folder

SRC = src/main.c src/system.c \
			src/cpu.c \
			src/memory.c \
			src/uptime.c \
			src/disk.c \
			src/process.c
 #source , and can add other sources as well

TARGET = build/system-monitor 


#put the executable here build/system-monitor

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) 
	