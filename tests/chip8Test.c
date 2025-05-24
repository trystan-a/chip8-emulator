#include <stdio.h>
#include <stdlib.h>
#include "chip8.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

//eventually replace with CUnit for unit testing, just testing functionality for now
//current problems:
//memory printing incorrectly (prints only one 0 if there are two 0's back to back) (i think its still correct in memory but doesnt print correctly so hard to verify)
int main(int agrc, char** argv) {
    chip8 myChip8;

    initialize(&myChip8);
    readROM(&myChip8, "roms/15PUZZLE");

    printf("Current opcode: %i\n", myChip8.opcode);
    printf("Current index register (I): %i\n", myChip8.I);
    printf("Current program counter (PC): %x\n", myChip8.pc);
    printf("Current stack pointer (SP): %i\n", myChip8.sp);

    printf("\nCurrent memory contents:\n");
    for(int i = 0; i < 4096; i++) {
        printf("%x", myChip8.memory[i]);
    }

    printf("\n\nCurrent stack contents:\n");
    for(int i = 0; i < 16; i++) {
        printf("%i", myChip8.stack[i]);
    }

    unsigned short opcode = 0;

    opcode = myChip8.memory[0x200 + 12] << 8 | myChip8.memory[0x200 + 13]; //checking individual opcodes (first opcode is at 0x200 + 0 and 0x200 + 1)

    printf("\n\nCurrent opcode: %.4x", opcode);

    return 0;
}