/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_ttf_to_layer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:47:44 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/20 17:46:20 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL_ttf.h"
#include "libui_ttf.h"
#include "SDL_surface.h"
#include "bmp_parser.h"

inline static void	fill_color(SDL_Color *color, unsigned user_color)
{
	t_bmp_32	divided;

	divided = hex_to_bit32_pixel(user_color);
	*color = (SDL_Color){divided.r, divided.g, divided.b, divided.a};
}

inline static void	fill_layer(SDL_Surface *surface, t_ui_layer *layer, \
								t_ui_ttf_param param)
{
	layer->width = surface->w;
	layer->height = surface->h;
	layer->x = param.x;
	layer->y = param.y;
	layer->rescale_h = param.height;
	layer->rescale_w = param.width;
	if (!(layer->pixels = ft_memdup(surface->pixels, layer->width \
									* layer->height * sizeof(unsigned))))
		return (ft_putendl_fd("Erreur lors de la conversion du TTF.", 2));
}

t_ui_layer			ui_ttf_to_layer(char *path, char *txt, t_ui_ttf_param param)
{
	t_ui_layer	layer;
	TTF_Font	*police;
	SDL_Surface	*surface;
	SDL_Color	color;

	ft_bzero(&layer, sizeof(t_ui_layer));
	police = NULL;
	surface = NULL;
	if (TTF_Init() == -1)
	{
		ft_putstr_fd("Erreur d'initialisation de TTF_Init: ", 2);
		ft_putendl_fd(TTF_GetError(), 2);
		return (layer);
	}
	if (!(police = TTF_OpenFont(path, 65)))
	{
		ft_putstr_fd("La font est introuvable: ", 2);
		ft_putendl_fd(path, 2);
		return (layer);
	}
	fill_color(&color, param.color);
	if (!(surface = TTF_RenderText_Blended(police, txt, color)))
	{
		ft_putstr_fd("Erreur lors du dessin du texte: ", 2);
		ft_putendl_fd(TTF_GetError(), 2);
		return (layer);
	}
	fill_layer(surface, &layer, param);
	TTF_CloseFont(police);
	TTF_Quit();
	return (layer);
}
