# Compiler
CC = gcc

# Compiler flags
# -Wall: Enable all compiler's warning messages
# -Wextra: Enable extra warning flags not enabled by -Wall
# --coverage: Generate coverage information for gcov
CFLAGS = -Wall -Wextra --coverage

# Test files
Test_files = test.txt test2.txt test3.txt test4.txt test5.txt

# Default target, builds the main executable
all: main

# Rule to build the main executable
# $@ matches the target (main)
# $< matches the first prerequisite (main.o)
main: main.o
	$(CC) $(CFLAGS) -o $@ $<

# Rule to build the object file from the source file
# $@ matches the target (main.o)
# $< matches the first prerequisite (main.c)
main.o: main.c
	$(CC) $(CFLAGS) -c $<

# Rule to run the main executable with the test files
# The -for loop runs the main executable with each test file as input
exam: 
	-for file in $(Test_files); do \
		./main < $$file; \
	done

# Rule to clean the build files
# Removes the main executable, object file, and coverage files
clean:
	@rm -f main main.o main.gcno main.gcda
