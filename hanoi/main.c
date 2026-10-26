#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hanoi.h"

// Constantes de la ventana
const int SCREEN_WIDTH = 780;
const int SCREEN_HEIGHT = 550;
#define FONT_PATH "./font.TTF"

// Función para dibujar texto en la ventana
void drawText(SDL_Renderer* renderer, TTF_Font* font, const char* text, int x, int y, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = {x, y, texW, texH};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void drawCenteredText(SDL_Renderer* renderer, TTF_Font* font, const char* text, int y, SDL_Color color) {
    int texW = 0;
    int texH = 0;
    TTF_SizeText(font, text, &texW, &texH);
    int x = (SCREEN_WIDTH - texW) / 2;
    drawText(renderer, font, text, x, y, color);
}

void resetInput(char* inputText, bool* inputActive, bool* resetPrompt, bool* solving, Hanoi** hanoi) {
    inputText[0] = '\0';
    *inputActive = true;
    *resetPrompt = false;
    *solving = false;
    if (*hanoi) {
        freeHanoi(*hanoi);
        *hanoi = NULL;
    }

    // Limpiar todos los eventos pendientes en el buffer
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        // Vaciar el buffer de eventos
    }
}

int main(int argc, char* args[]) {
    // Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {  // Agregar SDL_INIT_AUDIO
        printf("No se pudo inicializar SDL. SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Inicializar SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
        printf("No se pudo inicializar SDL_mixer. SDL_mixer Error: %s\n", Mix_GetError());
        SDL_Quit();
        return 1;
    }

    // Inicializar SDL_ttf
    if (TTF_Init() == -1) {
        printf("No se pudo inicializar SDL_ttf. SDL_ttf Error: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }

    // Crear la ventana
    SDL_Window* window = SDL_CreateWindow("Torres de Hanoi", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("No se pudo crear la ventana. SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Crear el renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("No se pudo crear el renderer. SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Cargar la fuente TTF
    TTF_Font* font = TTF_OpenFont(FONT_PATH, 35); // Tamaño de fuente actualizado a 35
    if (font == NULL) {
        printf("Error al cargar la fuente: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Cargar el efecto de sonido
    Mix_Chunk* woodEffect = Mix_LoadWAV("woodEfect.mp3");
    if (woodEffect == NULL) {
        printf("No se pudo cargar woodEfect.mp3. SDL_mixer Error: %s\n", Mix_GetError());
        TTF_CloseFont(font);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    // Variable para almacenar el nmúero de discos
    char inputText[255] = "";
    bool inputActive = true;
    bool solving = false;
    bool resetPrompt = false;
    bool showMenu = true;

    // Loop principal
    int quit = 0;
    Hanoi* hanoi = NULL;
    int numDiscs = 0;

    while (!quit) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            } else if (e.type == SDL_TEXTINPUT && inputActive) {
                strcat(inputText, e.text.text);
            } else if (e.type == SDL_KEYDOWN) {
                if (showMenu) {
                    if (e.key.keysym.sym == SDLK_RETURN) {
                        showMenu = false;
                    }
                } else if (inputActive) {
                    if (e.key.keysym.sym == SDLK_RETURN) {
                        inputActive = false;
                        numDiscs = atoi(inputText);
                        if (numDiscs < 1 || numDiscs>8) {
                            printf("Número de discos inválido.\n");
                            resetInput(inputText, &inputActive, &resetPrompt, &solving, &hanoi);
                        } else {
                            // Resolver las torres
                            hanoi = createHanoi(numDiscs);
                            drawHanoi(hanoi, renderer);  // Mostrar el estado inicial
                            SDL_RenderPresent(renderer);
                            solving = true;
                        }
                    } else if (e.key.keysym.sym == SDLK_BACKSPACE && strlen(inputText) > 0) {
                        inputText[strlen(inputText) - 1] = '\0';
                    }
                } else if (resetPrompt) {
                    if (e.key.keysym.sym == SDLK_r) {
                        resetInput(inputText, &inputActive, &resetPrompt, &solving, &hanoi);
                    } else if (e.key.keysym.sym == SDLK_ESCAPE) {
                        quit = 1;
                    }
                }
            }
        }

        // Limpiar la pantalla con el color deseado
        SDL_SetRenderDrawColor(renderer, 215, 170, 168, 255); 
        SDL_RenderClear(renderer);

        // Dibujar la interfaz de entrada de txeto o el menú
        SDL_Color textColor = {0, 0, 0, 255};
        if (showMenu) {
            drawCenteredText(renderer, font, "Bienvenido a Torres de Hanoi :D", SCREEN_HEIGHT / 2 - 50, textColor);
            drawCenteredText(renderer, font, "Presione Enter para comenzar", SCREEN_HEIGHT / 2, textColor);
        } else if (inputActive) {
            drawCenteredText(renderer, font, "Ingrese el numero de discos y presione Enter:", SCREEN_HEIGHT / 2 - 50, textColor);
            drawCenteredText(renderer, font, inputText, SCREEN_HEIGHT / 2, textColor);
        } else if (solving) {
            solveHanoi(hanoi, numDiscs, 0, 2, 1, renderer, &quit, woodEffect);
            solving = false;  // Solo se ejecuta una vez
            resetPrompt = true;
            SDL_Delay(1500);  // Esperar después de resolver
        } else if (resetPrompt) {
            drawCenteredText(renderer, font, "Solucion completada.", SCREEN_HEIGHT / 2 - 60, textColor);
            drawCenteredText(renderer, font, "Presione 'r' para reiniciar o ESC para salir.", SCREEN_HEIGHT / 2 - 20, textColor);
        }

        // Actualizar la ventana
        SDL_RenderPresent(renderer);

        // Esperar paravolver a renderizar para evitar un uso excesivo de la CPU
        SDL_Delay(20);
    }

    // Limpiar y cerrar SDL
    Mix_FreeChunk(woodEffect);  // Liberar el efecto de sonido
    Mix_CloseAudio(); 
    if (hanoi) freeHanoi(hanoi);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
