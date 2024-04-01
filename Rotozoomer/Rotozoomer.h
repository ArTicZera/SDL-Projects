double angle = 0.0;
double zoom = 1.00;
double zoomspeed = 0.01;

void Rotozoomer(SDL_Renderer* renderer, int w, int h, int i)
{
    double cosa = cos(angle);
    double sina = sin(angle);

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            int cx = x - (w / 2);
            int cy = y - (h / 2);

            cx /= zoom;
            cy /= zoom;

            cx += 500; cy += 500;

            int zx = cx * cosa - cy * sina;
            int zy = cx * sina + cy * cosa;

            int fx = 255 * ((zx ^ zy) & 10000);

            SDL_SetRenderDrawColor(renderer, fx, fx, fx, 0xFF);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }

    angle += 0.01;
    zoom += zoomspeed;

    if (zoom > 2.0 || zoom < 0.1) zoomspeed *= -1;

    SDL_Delay(10);
}