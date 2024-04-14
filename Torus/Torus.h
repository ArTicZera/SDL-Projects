#define POINTS 200

float angle = 0.0;

void Torus(SDL_Renderer* renderer, int w, int h, int i)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
	SDL_RenderClear(renderer);

	float majr = 100.0;
	float minr = 50.0;

	for (int j = 0; j < POINTS; j++)
	{
		for (int k = 0; k < POINTS; k++)
		{
			float theta = 2 * M_PI * j / POINTS;
			float phi = 2 * M_PI * k / POINTS;

			VERTEX vtx =
			{
				(majr + minr * cos(phi)) * cos(theta),
				(majr + minr * cos(phi)) * sin(theta),
				minr * sin(phi)
			};

			int zx = 128.0 + (128.0 * sin(k / 64.0));
			int zy = 128.0 + (128.0 * sin(j / 32.0));
			int zz = 128.0 + (128.0 * sin(sqrt(k * j + k * j) / 16.0));
			Uint8 fx = zx + zy + zz;
			//Uint8 fx = int(vtx.x) ^ int(vtx.y);

			_3D::RotateX(&vtx, angle);

			vtx.x += w / 2;
			vtx.y += h / 2;

			SDL_SetRenderDrawColor(renderer, palette[fx].r, palette[fx].g, palette[fx].b, 0xFF);
			SDL_RenderDrawPoint(renderer, vtx.x, vtx.y);
		}
	}

	angle += 0.01;
	
	SDL_Delay(10);
}