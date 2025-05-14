CC = gcc
CFLAGS = -I./include -Wall
SRC = src/
BIN = bin/

all: chip8

chip8.o: $(SRC)chip8.c
	$(CC) $(CFLAGS) -c $(SRC)chip8.c -o $(BIN)chip8.o

main.o: $(SRC)main.c
	$(CC) $(CFLAGS) -c $(SRC)main.c -o $(BIN)main.o

chip8: chip8.o main.o
	$(CC) $(CFLAGS) $(BIN)chip8.o $(BIN)main.o -o chip8 -lSDL3

clean:
	rm -f $(BIN)*.o chip8