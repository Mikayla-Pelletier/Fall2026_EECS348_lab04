# This is a comment line
CC=gcc
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -Wall 
all: prog 
prog: task1.o task2.o
	$(CC) task1.o task2.o -o prog
task1.o: task1.c
	$(CC) $(CFLAGS) task1.c
task2.o: task2.c
	$(CC) $(CFLAGS) task2.c
clean:
	rm -rf *.o
	rm -rf prog