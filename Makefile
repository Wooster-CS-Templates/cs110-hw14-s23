CFLAGS=-std=c99 -Wall
CC=gcc

pointer_parameters: pointer_parameters.o main.o
	$(CC) $(CFLAGS) pointer_parameters.o main.o -o pointer_parameters

test: pointer_parameters.o test.o
	$(CC) $(CFLAGS) pointer_parameters.o test.o -o test

test.o: tests/test.c pointer_parameters.h
	$(CC) $(CFLAGS) -c tests/test.c

main.o: main.c pointer_parameters.h
	$(CC) $(CFLAGS) -c main.c

pointer_parameters.o: pointer_parameters.h pointer_parameters.c
	$(CC) $(CFLAGS) -c pointer_parameters.c

gh-test-pointer-parameters: clean test
	./test

clean:
	rm -f pointer_parameters *.o
