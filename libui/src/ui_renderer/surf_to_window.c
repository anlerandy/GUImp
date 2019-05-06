#include "libui.h"

void	surf_to_window(SDL_Surface *surf, SDL_Window *win, t_size pos)
{
	int i;
	int len;

	i = 0;
	len = (surf->w + pos.x < win->w) ? surf->w : 2 * surf->w - win->w - pos.x;
	len *= sizeof(int);
	if (len <= 0)
		return ;
	while (i < surf->h && i + pos.x < win->h)
	{
		ft_memcpy(&(win->pixels[(pos.x + (pos.y + i) * win->w) * sizeof(int)]),
			surf->pixels[i * surf->w * sizeof(int)]	,len);
		i++;
	}
}