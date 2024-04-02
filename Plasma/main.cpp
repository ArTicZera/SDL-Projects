/*
    Plasma - by ArTic/JhoPro
*/

#include "../Header.h"
#include "Plasma.h"

const int w = 420;
const int h = 320;

bool quit = false;

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

    SDL_Window* window = SDL_CreateWindow("Text Wave", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(renderer, w, h);

    SetPalette();

    bool conditionA = true;
    bool conditionB = false;
    int i = 0;

    while (!quit)
    {
        Plasma(renderer, w, h, i);

        SDL_RenderPresent(renderer);

        SetupEvents();

        if (conditionA)
        {
            i++;

            if (i > 128)
            {
                conditionA = false;
                conditionB = true;
            }
        }

        if (conditionB)
        {
            i--;

            if (i < 1)
            {
                conditionA = true;
                conditionB = false;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}