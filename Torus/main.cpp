/*
    Plasma - by ArTic/JhoPro
*/

#include "../Header.h"
#include "Torus.h"

const int w = 420;
const int h = 320;

bool quit = false;

Uint8 sinetable[256];

void SetupEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) quit = true;
                break;
        }
    }
}

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("Text Wave", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(renderer, w, h);

    SetPalette();

    int i = 0;

    while (!quit)
    {
        Torus(renderer, w, h, i);

        SDL_RenderPresent(renderer);

        SetupEvents();

        i++;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}