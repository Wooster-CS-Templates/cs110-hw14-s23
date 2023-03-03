CFLAGS=-std=c99 -Wall
CC=gcc

pointer_parameters: pointer_parameters.o main.o
	$(CC) $(CFLAGS) pointer_parameters.o main.o -o pointer_parameters

main.o: main.c pointer_parameters.h
	$(CC) $(CFLAGS) -c main.c

pointer_parameters.o: pointer_parameters.h pointer_parameters.c
	$(CC) $(CFLAGS) -c pointer_parameters.c

gh-test-pointer-parameters: clean pointer_parameters
	./pointer_parameters

clean:
	rm -f pointer_parameters *.o
