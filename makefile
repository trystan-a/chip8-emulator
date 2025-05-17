CC = gcc
CFLAGS = -I./include -Wall
SRC = src/
BIN = bin/
TEST = tests/

all: bin chip8 chip8Test

bin:
	mkdir -p bin

chip8.o: $(SRC)chip8.c
	$(CC) $(CFLAGS) -c $(SRC)chip8.c -o $(BIN)chip8.o

main.o: $(SRC)main.c
	$(CC) $(CFLAGS) -c $(SRC)main.c -o $(BIN)main.o

chip8Test.o: $(TEST)chip8Test.c
	$(CC) $(CFLAGS) -c $(TEST)chip8Test.c -o $(BIN)chip8Test.o

chip8: chip8.o main.o
	$(CC) $(CFLAGS) $(BIN)chip8.o $(BIN)main.o -o chip8 -lSDL3

chip8Test: chip8.o chip8Test.o
	$(CC) $(CFLAGS) $(BIN)chip8.o $(BIN)chip8Test.o -o chip8Test -lSDL3

clean:
	rm -f $(BIN)*.o chip8 chip8Test