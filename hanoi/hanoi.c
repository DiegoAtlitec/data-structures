#include <stdlib.h>
#include <stdio.h>
#include <SDL_mixer.h>
#include "hanoi.h"

Hanoi* createHanoi(int n) {
    Hanoi* hanoi = (Hanoi*)malloc(sizeof(Hanoi));
    hanoi->numDiscs = n; // Inicializa numDiscs

    for (int i = 0; i < 3; i++) {
        hanoi->rods[i] = createStack();
    }
    for (int i = n; i > 0; i--) {
        push(hanoi->rods[0], i);
    }
    return hanoi;
}

void solveHanoi(Hanoi* hanoi, int n, int from, int to, int aux, SDL_Renderer* renderer, int* quit, Mix_Chunk* woodEffect) {
    // Dibujar el estado inicial de las torres
    drawHanoi(hanoi, renderer);

    SDL_Delay(360);

    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            *quit = 1;
            return;
        }
    }

    if (*quit) return;  
    if (n == 1) {
        int disk = pop(hanoi->rods[from]);
        push(hanoi->rods[to], disk);
        printf("Mover disco 1 de %d a %d\n", from + 1, to + 1);
        Mix_PlayChannel(-1, woodEffect, 0);  
        drawHanoi(hanoi, renderer);
        SDL_Delay(500);

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                *quit = 1;
                return;
            }
        }

        return;
    }
    solveHanoi(hanoi, n - 1, from, aux, to, renderer, quit, woodEffect);
    if (*quit) return;  // Salida
    int disk = pop(hanoi->rods[from]);
    push(hanoi->rods[to], disk);
    printf("Mover disco %d de %d a %d\n", n, from + 1, to + 1);
    Mix_PlayChannel(-1, woodEffect, 0);  
    drawHanoi(hanoi, renderer);

    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            *quit = 1;
            return;
        }
    }

    solveHanoi(hanoi, n - 1, aux, to, from, renderer, quit, woodEffect);
    if (*quit) return;  // Salida
}

void drawHanoi(Hanoi* hanoi, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 215, 170, 168, 255);
    SDL_RenderClear(renderer);

    SDL_Color diskColors[] = {
        {255, 0, 0, 255},
        {0, 255, 0, 255},
        {0, 0, 255, 255},
        {255, 255, 0, 255},
        {0, 255, 255, 255},
        {255, 0, 255, 255},
        {128, 0, 128, 255},
        {255, 165, 0, 255},
    };

    int rodX[3] = {185, 385, 585};
    int rodBaseY = 375; // Ajuste la posición base de los palos 
    int rodWidth = 10;
    int rodHeight = 200;

    int maxDiskWidth = 150;
    int diskHeight = 20;
    int diskGap = 0; // Disminuya este valor para reducir la separación vertical entre los discos

    for (int i = 0; i < 3; i++) {
        // Configurar el color de los palos antes de dibujarlos
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_Rect rodRect = {rodX[i] - rodWidth / 2, rodBaseY - rodHeight, rodWidth, rodHeight};
        SDL_RenderFillRect(renderer, &rodRect);

        Node* aux = hanoi->rods[i]->top;
        int y = rodBaseY - diskHeight; // Comienza desde la base de la torre

        // Calcula el número de discos en la torre
        int numDiscs = 0;
        while (aux != NULL) {
            numDiscs++;
            aux = aux->next;
        }

        aux = hanoi->rods[i]->top;
        for (int j = numDiscs - 1; j >= 0; j--) {
            int diskWidth = (aux->data * maxDiskWidth) / hanoi->numDiscs; // Ajuste de ancho basado en el valor del disco y el número total de discos

            // Configurar el color del disco
            SDL_Color color = diskColors[(aux->data - 1) % 8];
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
            
            // Dibujar el disco
            SDL_Rect diskRect = {rodX[i] - diskWidth / 2, y - j * (diskHeight + diskGap), diskWidth, diskHeight}; // Ajuste de posición vertical
            SDL_RenderFillRect(renderer, &diskRect);

            aux = aux->next;
        }
    }

    SDL_RenderPresent(renderer);
}

void freeHanoi(Hanoi* hanoi) {
    for (int i = 0; i < 3; i++) {
        freeStack(hanoi->rods[i]);
    }
    free(hanoi);
}
