CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

all: divideByZero stackOverFlow undefinedMemory

divideByZero: divideByZero.o
	$(CC) $(CFLAGS) -o $@ $^

stackOverFlow: stackOverFlow.o
	$(CC) $(CFLAGS) -o $@ $^

undefinedMemory: undefinedMemory.o
	$(CC) $(CFLAGS) -o $@ $^

divideByZero.o: divideByZero.c
	$(CC) $(CFLAGS) -c $<

stackOverFlow.o: stackOverFlow.c
	$(CC) $(CFLAGS) -c $<

undefinedMemory.o: undefinedMemory.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f divideByZero stackOverFlow undefinedMemory *.o