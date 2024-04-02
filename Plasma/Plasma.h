void Plasma(SDL_Renderer* renderer, int w, int h, int i)
{
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            int zx = i + (i * sin(x / 64.0));
            int zy = i + (i * sin(y / 32.0));
            int zz = i + (i * sin(sqrt(x * x + y * y) / 16.0));
            int ax = rand() % 16;

            Uint8 fx = (zx + zy + zz + ax) / 6;

            SDL_SetRenderDrawColor(renderer, palette[fx].r, palette[fx].r, palette[fx].r, 0xFF);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}