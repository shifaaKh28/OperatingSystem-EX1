CC = gcc
CFLAGS = -g -fPIC
DLFLAGS = -shared

all: main
# Target to build the main executable
main: main.o libpoisson.so 
	$(CC) $(CFLAGS) -o $@ main.o ./libpoisson.so

# Target to build the shared library libpoisson.so
libpoisson.so: poisson.o
	$(CC) $(CFLAGS) $(DLFLAGS) -o $@ $^ -lm

main.o: main.c poisson.h
	$(CC) $(CFLAGS) -c main.c -o main.o

poisson.o: poisson.c poisson.h
	$(CC) $(CFLAGS) -c poisson.c -o poisson.o -lm

.PHONY: clean all

clean: 
	rm -f main *.o *.so