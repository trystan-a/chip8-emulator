#include "../include/chip8.h" //fix this (including an absolute path is bad practice)

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
    for(int i = 0; i < 15; i++) {
        myChip8->stack[i] = 0;
    }

    //clear all registers
    for(int i = 0; i < 15; i++) {
        myChip8->V[i] = 0;
    }

    //clear memory
    for(int i = 0; i < 4095; i++) {
        myChip8->memory[i] = 0;
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