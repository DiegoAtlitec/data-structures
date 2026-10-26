#ifndef HANOI_H
#define HANOI_H

#include "stack.h"
#include <SDL.h>

typedef struct {
    Stack* rods[3];
    int numDiscs;
} Hanoi;


Hanoi* createHanoi(int n);
void solveHanoi(Hanoi* hanoi, int n, int from, int to, int aux, SDL_Renderer* renderer, int* quit, Mix_Chunk* woodEffect);
void drawHanoi(Hanoi* hanoi, SDL_Renderer* renderer);
void freeHanoi(Hanoi* hanoi);

#endif
