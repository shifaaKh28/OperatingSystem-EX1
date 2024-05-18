CC = gcc
CFLAGS = -Wall -Wextra

all: findPhone add2pb

findPhone: findPhone.o
	$(CC) $(CFLAGS) -o findPhone findPhone.o

add2pb: add2pb.o
	$(CC) $(CFLAGS) -o add2pb add2pb.o

findPhone.o: findPhone.c
	$(CC) $(CFLAGS) -c findPhone.c

add2pb.o: add2pb.c
	$(CC) $(CFLAGS) -c add2pb.c

clean:
	rm -f findPhone add2pb *.o