#include <stdio.h>
#include <stdlib.h>
#include "chip8.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

//eventually replace with CUnit for unit testing, just testing functionality for now
int main(int agrc, char** argv) {
    chip8 myChip8;

    initialize(&myChip8);

    printf("Current opcode: %i\n", myChip8.opcode);
    printf("Current index register (I): %i\n", myChip8.I);
    printf("Current program counter (PC): %i\n", myChip8.pc);
    printf("Current stack pointer (SP): %i\n", myChip8.sp);

    printf("\nCurrent memory contents:\n");
    for(int i = 0; i < 4095; i++) {
        printf("%i", myChip8.memory[i]);
    }

    return 0;
}