#include <stdio.h>
#include "chip8.h"

void initialize(chip8 *myChip8) {
    // used to define the font of the characters
    // how to interpret these: lets look at 0 for example
    // 0xF0 in hex is = 1111 0000
    // 0x90 in hex is = 1001 0000
    // 0x90 in hex is = 1001 0000
    // 0x90 in hex is = 1001 0000
    // 0xF0 in hex is = 1111 0000
    //creating a 0 in binary
    unsigned char chip8Fontset[80] =
        { 
            0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
            0x20, 0x60, 0x20, 0x20, 0x70, // 1
            0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
            0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
            0x90, 0x90, 0xF0, 0x10, 0x10, // 4
            0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
            0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
            0xF0, 0x10, 0x20, 0x40, 0x40, // 7
            0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
            0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
            0xF0, 0x90, 0xF0, 0x90, 0x90, // A
            0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
            0xF0, 0x80, 0x80, 0x80, 0xF0, // C
            0xE0, 0x90, 0x90, 0x90, 0xE0, // D
            0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
            0xF0, 0x80, 0xF0, 0x80, 0x80  // F
        };

    myChip8->pc = 0x200;
    myChip8->opcode = 0;
    myChip8->I = 0;
    myChip8->sp = 0;

    //clear stack
    for(int i = 0; i < 16; i++) {
        myChip8->stack[i] = 0;
    }

    //clear all registers
    for(int i = 0; i < 16; i++) {
        myChip8->V[i] = 0;
    }

    //clear all keys
    for(int i = 0; i < 16; i++) {
        myChip8->keys[i] = 0;
    }

    //clear memory
    for(int i = 0; i < 4096; i++) {
        myChip8->memory[i] = 0;
    }

    //clear screen
    for(int i = 0; i < 2048; i++) {
        myChip8->gfx[i] = 0;
    }

    //load fontset
    //start loading fontset at memory location 0x050 as per memory map (80 in decimal)
    for(int i = 0; i < 80; i++) {
        myChip8->memory[i + 0x050] = chip8Fontset[i];
    }

    //reset timers
    //come back to this as this is probably wrong (buzzer sounds once it reaches 0)
    myChip8->delayTimer = 0;
    myChip8->soundTimer = 0;
}

int readROM(chip8 *myChip8, char *ROM) {
    FILE *fptr = fopen(ROM, "rb");

    if(fptr == NULL) {
        return 1; //error code 1 is a file error
    }

    fseek(fptr, 0, SEEK_END); //getting the size of the ROM
    size_t ROMSize = ftell(fptr);

    rewind(fptr); //rewinding ROM binary file so that I can read data into memory until the end using the size

    fread(&myChip8->memory[0x200], sizeof(unsigned char), ROMSize, fptr); //reading the contents of the rom delimited by size unsigned char into memory
    fclose(fptr);

    return 0;
}

void executeCycle(chip8 *myChip8) {
    //fetch opcode
    //each opcode is stored as two bytes in memory, so we read first byte and shift the bits to the left by 8 bits
    //then we read the next byte by using the bitwise or operator to not only read the new bits, but keep the old ones
    myChip8->opcode = myChip8->memory[myChip8->pc] << 8 | myChip8->memory[myChip8->pc + 1];

    //decode opcode
    //using the bitwise and operator to extract the first digit of the opcode, which lets us determine what function that opcode is supposed to do
    //some opcodes rely on more than the first opcode to determine function, use a nested switch statement for those
    switch(myChip8->opcode & 0xF000) {
        default:
            printf ("\nUnknown opcode: %.4X\n", myChip8->opcode);
    }
}