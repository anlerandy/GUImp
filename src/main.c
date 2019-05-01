#include "guimp.h"

int main()
{
	t_win		*win;
	SDL_Event	e;
	int 		flag;
	t_bmp		bmpfile;

	bmpfile = ui_getbmp("/home/woap-unix/GUImp/libui/src/ui_bmp//800_600/24bit.bmp");
	win = ui_new_window(bmpfile.info.width, bmpfile.info.height);
	while(1)
	{
		flag = 1;
		while (flag || SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN &&
						e.key.keysym.sym == SDLK_ESCAPE))
				exit(1);
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
				exit(1);
			flag = 0;
		}
		ft_memcpy(win->s->pixels, bmpfile.pixels,
				(sizeof(unsigned) * bmpfile.pixel_count));
		SDL_UpdateWindowSurface(win->w);
	}
}
