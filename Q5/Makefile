CC = gcc
CFLAGS = -Wall -pg

all: algo1 algo2 algo3

algo1: algo1.c
	$(CC) $(CFLAGS) -o algo1 algo1.c

algo2: algo2.c
	$(CC) $(CFLAGS) -o algo2 algo2.c

kadanes_alg: algo3.c
	$(CC) $(CFLAGS) -o algo3 algo3.c

.PHONY: clean all

clean:
	rm -f algo1 algo2 algo3