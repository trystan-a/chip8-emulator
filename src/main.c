#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "chip8.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main(int argc, char** argv) {
    SDL_Window *window;
    SDL_Event event;
    chip8 myChip8;
    int errorCode = 0;
    bool isRunning = true;
    char userInput[sizeof(argv[1] + 5)] = "roms/"; //need to concatenate roms/ at beginning of rom name to access it in a different directory
    //FIX THIS at some point as referring to path names in variables is bad practice (i think)

    if(argc < 2) {
        printf("Invalid ROM. Input ROM name through command line arguement.");
        return 1; //error 1 means rom issue
    }

    SDL_Init(SDL_INIT_VIDEO); //initialize SDL video
    window = SDL_CreateWindow("CHIP-8 Emulator", 640, 320, 0); //create SDL window with 640x320 dimensions

    if(window == NULL) {
        printf("Error creating window");
        return 2; //error 2 means sdl3 issue
    }

    initialize(&myChip8);

    strcat(userInput, argv[1]); //concatenating /roms infront of rom name

    errorCode = readROM(&myChip8, userInput); //error code will be 0 if the rom was read successfully

    if(errorCode != 0) { //if rom name doesnt exist
        printf("Invalid ROM. Input a valid ROM name from the roms directory.");
        return 1;
    }
    
    //emulation loop
    while(isRunning) {
        while(SDL_PollEvent(&event) != 0) { //handling SDL events (only handling exit event for now)
            switch(event.type) {
                case SDL_EVENT_QUIT:
                    isRunning = false;
                    break;
            }
        }

        executeCycle(&myChip8);
    }

    SDL_DestroyWindow(window); //cleaning up SDL
    SDL_Quit();
    return 0;
}