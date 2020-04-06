# Name: Lindsey Reynolds
# Date: 03/31/20
# Title: Lab 4 Makefile


all: queue_test fifo

queue_test: queue_test.c
	gcc -o queue_test queue_test.c queue.c node.c -Wall -Werror

fifo: fifo.c
	gcc -o fifo fifo.c queue.c node.c -Wall

clean:
	rm -f fifo queue_test