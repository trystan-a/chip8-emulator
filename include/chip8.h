#ifndef CHIP8_H_ //guard
#define CHIP8_H_

typedef struct { //used to represent everything in the chip8 "architecture"
    unsigned short opcode; //stores the current 2 byte opcode

    //memory map:
    //0x000-0x1FF: chip8 interpreter (think of it as a vm environment that can interpret and execute chip8 programs)
    //0x050-0x0A0: used for 4x5 pixel font set (0-F)
    //0x200-0xFFF: program rom and work ram
    unsigned char memory[4096]; //holds the memory of the the chip8 (4096 one byte values)

    unsigned char V[16]; //16 one byte registers V[0]-V[E] with V[F] being used for the carry flag

    //can have values between 0x000-0xFFF
    unsigned short I; //index register
    unsigned short pc; //program counter

    //used to represent the graphics on the screen (chip8 only supports black or white so 0 = black/off and 1 = white/on)
    //the display of a chip8 program is 64x32 or 2048 pixels
    unsigned char gfx[64 * 32];

    unsigned char delayTimer; //timer that counts down to 0 if the value is ever 0. can be a max of 255. used for general timing
    unsigned char soundTimer; //timer that counts down to 0 if the value is ever 0. can be a max of 255. sounds a buzzer after counting down to 0

    unsigned short stack[16]; //16 levels of stack, 2 bytes to store addresses
    unsigned short sp; //stack pointer, used to keep track of where in the stack we currently are

    unsigned char keys[16]; //chip8 uses a 4x4 keypad, status of keys is stored in a 1 byte array (0 = off/not pressed, 1 = on/pressed)
} chip8;

#endif