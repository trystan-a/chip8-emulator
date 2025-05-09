#include <stdio.h>
#include <stdlib.h>
#include "../include/chip8.h" //fix this (including an absolute path is bad practice)
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

// compile with this command for now:
// gcc -Wall main.c chip8.c -o chip8 -lSDL3
int main(int agrc, char** argv) {
    SDL_Window *window;
    chip8 myChip8;

    SDL_Init(SDL_INIT_VIDEO); //initialize SDL video
    window = SDL_CreateWindow("Chip8 Emulator", 640, 320, 0); //create SDL window with 640x320 dimensions

    if(window == NULL) {
        printf("Error creating window");
        return 1;
    }

    initialize(&myChip8);
    
    //game loop here

    SDL_DestroyWindow(window); //cleaning up DSL
    SDL_Quit();
    return 0;
}