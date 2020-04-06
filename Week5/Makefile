# Name: Lindsey Reynolds
# Date: 04/07/20
# Title: Lab 5 Makefile

all: threadHello matrix

threadHello: threadHelloFixed_step1_Fixed.c
	gcc -o threadHello threadHelloFixed_step1_Fixed.c -Wall -pthread

matrix: matrix_multiplication.c
	gcc -o matrix matrix_multiplication.c -Wall -pthread

clean:
	rm -f threadHello matrix