# Makefile for compiling nfl-score-program.c

# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Target executable name
TARGET = nfl-score-program

# Default rule
all: $(TARGET)

# Rule to link the object file into the executable
$(TARGET): nfl-score-program.o
	$(CC) $(CFLAGS) -o $(TARGET) nfl-score-program.o

# Rule to compile the source file into an object file
nfl-score-program.o: nfl-score-program.c
	$(CC) $(CFLAGS) -c nfl-score-program.c

# Clean up generated files
clean:
	rm -f *.o $(TARGET)
