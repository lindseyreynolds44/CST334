# Name: Lindsey Reynolds
# Date: 02/17/20
# Title: Lab 2 Makefile
# Description: This program demonstrates the capabilities 
# of the fork(), execlp() and wait() functions.

# declare variables
CC=gcc
CFLAGS=-o

all: step1 step5

step1: lab2_step1.c
	$(CC) lab2_step1.c $(CFLAGS) output1

step5: lab2_step5.c
	$(CC) lab2_step5.c $(CFLAGS) output2

clean:
	rm output1 output2