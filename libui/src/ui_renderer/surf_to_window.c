#include "libft.h"
#include "libui.h"

void	ui_surf_to_window(SDL_Surface *surf, t_ui_win *win, t_ipos pos)
{
	int i;
	int len;
	int w;
	int h;

	i = 0;
	SDL_GetWindowSize(win->sdl_ptr, &w, &h);
	len = (surf->w + pos.x < w) ? surf->w : 2 * surf->w - w - pos.x;
	len *= sizeof(int);
	if (len <= 0)
		return ;
	while (i < surf->h && i + pos.x < h)
	{
		ft_memcpy(&(win->surf->pixels[(int)((pos.x + (pos.y + i) * w) * sizeof(int))]),
			&(surf->pixels[i * surf->w * sizeof(int)])	,len);
		i++;
	}
}

void	ui_surf_to_win_scale(SDL_Surface *surf, t_ui_win *win, t_ipos pos, double scale)
{
	int i;
	int j;
	t_isize size;
	int *winsurf;
	int *surfsurf;

	winsurf = (int*)win->surf->pixels;
	surfsurf = (int*)surf->pixels;
	SDL_GetWindowSize(win->sdl_ptr, &size.x, &size.y);
	j = (pos.y >= 0) ? pos.y : 0;	
	while (j < surf->h * scale + pos.y && j <= size.y)
	{
		i = (pos.x >= 0) ? pos.x : 0;
		while (i < (surf->w * scale) + pos.x && i <= size.x)
		{
			winsurf[i + j * size.x] = surfsurf[((int)((i - pos.x) / scale) + (int)((j - pos.y) / scale) * surf->w)];
			printf("pos : %d \n", ((int)((i - pos.x) / scale) + (int)((j - pos.y) / scale) * surf->w));
			printf("%x\n", surfsurf[((int)((i - pos.x) / scale) + (int)((j - pos.y) / scale) * surf->w)]);
	//		printf("i : %d , j : %d, max i %d, max j %d\n", i, j,(int)(surf->w * scale + pos.x), (int)(surf->h * scale + pos.y));
			printf("isurf : %d , jsurf : %d\n", (int)((i  - pos.x) / scale), (int)((j - pos.y) / scale));
			i++;
		}
		j++;
	}
	win->surf->pixels = winsurf;
}
/*
surf :
	x : 0 -> surf->w
	y : 0 -> surf->h
surf window :
	x : pos.x -> surf->w * scale + pos.x
	y : pos.y -> surf->y * scale + pos.y


* surf->w / 

*/