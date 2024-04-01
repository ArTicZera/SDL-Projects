/*
    Mandelbrot Explorer - by ArTic/JhoPro

    Z - Add Zoom
    X - Remove zoom

    AWSD - Walk
    
    E - Add iterations
    Q - Remove iterations

    MINUS/PLUS - Rotate

    ESCAPE - Exit
*/

#include "../Header.h"
#include "Mandelbrot.h"

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
                //Change Zoom
                if (event.key.keysym.sym == SDLK_z) mjzoom += 0.1;
                if (event.key.keysym.sym == SDLK_x) mjzoom -= 0.1;

                double adjust = exp2(mjzoom) * sign(mjzoom) / 10;

                //Walk
                if (event.key.keysym.sym == SDLK_a) hori += 0.01 / adjust;
                if (event.key.keysym.sym == SDLK_d) hori -= 0.01 / adjust;
                if (event.key.keysym.sym == SDLK_w) vert += 0.01 / adjust;
                if (event.key.keysym.sym == SDLK_s) vert -= 0.01 / adjust;
                
                //Change max iterations
                if (event.key.keysym.sym == SDLK_e) maxiter++;
                if (event.key.keysym.sym == SDLK_q) maxiter--;

                //Rotations
                if (event.key.keysym.sym == SDLK_MINUS)  mjangle += 0.01 / (adjust * 5);
                if (event.key.keysym.sym == SDLK_EQUALS) mjangle -= 0.01 / (adjust * 5);

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

    int i = 0;

    while (!quit)
    {
        Mandelbrot(renderer, w, h, i);

        SDL_RenderPresent(renderer);

        SetupEvents();

        i++;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}