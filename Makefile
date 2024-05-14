CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: poisson

poisson: poisson.c
	$(CC) $(CFLAGS) -o poisson poisson.c -lm

clean:
	rm -f poisson *.o
