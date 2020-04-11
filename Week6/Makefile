# Name: Lindsey Reynolds
# Date: 04/14/20
# Title: Lab 6 Makefile

# declare variables
CC=gcc -o
CFLAGS=-Wall -pthread

all: threadSync producerConsumer

threadSync: threadSync.c
	$(CC) threadSync threadSync.c $(CFLAGS)

producerConsumer: producerConsumer.c
	$(CC) producerConsumer producerConsumer.c $(CFLAGS)

clean:
	rm -f threadSync producerConsumer