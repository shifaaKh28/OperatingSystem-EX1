CC = gcc
CFLAGS = -Wall -Wextra --coverage 
Test_files = test.txt test2.txt test3.txt test4.txt test5.txt

all: main

main: main.o
	$(CC) $(CFLAGS) -o main main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

exam: 
	-for file in $(Test_files); do \
		./main < $$file; \
	done

clean:
	@rm -f main main.o main.gcno main.gcda
