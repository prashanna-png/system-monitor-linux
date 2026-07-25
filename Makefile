CC = gcc #compiler

CFLAGS = -Wall -Wextra -Iinclude  #search header inside include folder

SRC = src/main.c src/system.c #source , and can add other sources as well

TARGET = build/system-monitor #put the executable here build/system-monitor

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) 
	