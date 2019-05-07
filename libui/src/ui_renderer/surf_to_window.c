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