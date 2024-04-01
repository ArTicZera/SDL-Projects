int maxiter = 50;
double mjzoom = 0.0;
double hori = 0.73;
double vert = -0.01;
double mjangle = 0.0;

void Mandelbrot(SDL_Renderer* renderer, int w, int h, int i)
{
    double fractalX = (2.5 / (w * exp2(mjzoom) * sign(mjzoom)));
    double fractalY = (1.9 / (h * exp2(mjzoom) * sign(mjzoom)));

    SDL_Color color = { };

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            double cx = (x - w / 2.0) * fractalX - hori;
            double cy = (y - h / 2.0) * fractalY - vert;

            cx = cx * cos(mjangle) - cy * sin(mjangle);
            cy = cx * sin(mjangle) + cy * cos(mjangle);

            double zx = 0, zy = 0;

            Uint8 fx = 0;

            while (((zx * zx) + (zy * zy)) < 4 && fx < maxiter)
            {
                double fczx = zx * zx - zy * zy + cx;
                double fczy = 2 * zx * zy + cy;

                zx = fczx;
                zy = fczy;

                fx++;
            }

            fx += i;

            double smooth = fx + 1 - log(log(sqrt(zx * zx + zy * zy))) / log(2.0);

            HSVtoRGB(fmod(smooth * 10, 360.0), 1.0, 1.0, &color.r, &color.g, &color.b);

            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 0xFF);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}