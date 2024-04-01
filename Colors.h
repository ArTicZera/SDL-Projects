#pragma once

#include "Header.h"

typedef struct
{
    Uint8 r;
    Uint8 g;
    Uint8 b;
} RGBColor;

RGBColor palette[256];

void HSVtoRGB(float h, float s, float v, Uint8* r, Uint8* g, Uint8* b)
{
    int i;
    float f, p, q, t;

    if (s == 0)
    {
        *r = *g = *b = (Uint8)(v * 255);
        return;
    }

    h /= 60;
    i = (int)floor(h);
    f = h - i;
    p = v * (1 - s);
    q = v * (1 - s * f);                                                                                                                             
    t = v * (1 - s * (1 - f));                                                                                                                       
                                                                                                                                                     
    switch (i)                                                                                                                                       
    {
        case 0: *r = (Uint8)(v * 255); *g = (Uint8)(t * 255); *b = (Uint8)(p * 255); break;
        case 1: *r = (Uint8)(q * 255); *g = (Uint8)(v * 255); *b = (Uint8)(p * 255); break;
        case 2: *r = (Uint8)(p * 255); *g = (Uint8)(v * 255); *b = (Uint8)(t * 255); break;
        case 3: *r = (Uint8)(p * 255); *g = (Uint8)(q * 255); *b = (Uint8)(v * 255); break;
        case 4: *r = (Uint8)(t * 255); *g = (Uint8)(p * 255); *b = (Uint8)(v * 255); break;
        default: *r = (Uint8)(v * 255); *g = (Uint8)(p * 255); *b = (Uint8)(q * 255); break;
    }
}

void SetPalette()
{
    for (int i = 0; i < 256; i++)
    {
        float hue = fmod(i * 10, 360.0);
        float saturation = 1.0;
        float value = 1.0;

        HSVtoRGB(hue, saturation, value, &palette[i].r, &palette[i].g, &palette[i].b);
    }
}