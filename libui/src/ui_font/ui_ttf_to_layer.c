/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_ttf_to_layer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:47:44 by alerandy          #+#    #+#             */
/*   Updated: 2019/10/12 02:39:41 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL_ttf.h"
#include "libui_ttf.h"
#include "SDL_surface.h"
#include "ui_shared.h"
#include "libui_layers.h"

inline static SDL_Color		fill_color(unsigned user_color)
{
	t_bgra	divided;
	SDL_Color	color;

	divided = ui_hex_to_bgra(user_color);
	divided.a = (1 - divided.a / 255.) * 255;
	color = (SDL_Color){divided.r, divided.g, divided.b, divided.a};
	return (color);
}

inline static void			set_layer_size(SDL_Surface *surface, \
										t_ui_layer *layer, t_ui_ttf_param param)
{
	if (!param.width && !param.height)
	{
		layer->rescale_w = surface->w;
		layer->rescale_h = surface->h;
	}
	else if (!param.width && param.height)
	{
		layer->rescale_w = param.height * 100. / surface->h / 100. * surface->w;
		layer->rescale_h = param.height;
	}
	else if (param.width && !param.height)
	{
		layer->rescale_h = param.width * 100. / surface->w / 100. * surface->h;
		layer->rescale_w = param.width;
	}
	else
	{
		layer->rescale_w = param.width;
		layer->rescale_h = param.height;
	}
}

inline static void			fill_layer(SDL_Surface *surface, \
										t_ui_layer *layer, t_ui_ttf_param param)
{
	layer->width = surface->w;
	layer->height = surface->h;
	layer->x = param.x;
	layer->y = param.y;
	layer->width_inversed = param.inversed_w >= 0 ? 1 : -1;
	layer->height_inversed = param.inversed_h >= 0 ? 1 : -1;
	set_layer_size(surface, layer, param);
	if (!(layer->pixels = ft_memdup(surface->pixels, layer->width \
									* layer->height * sizeof(unsigned))))
		return (ft_putendl_fd("Erreur lors de la conversion du TTF.", 2));
}

static inline void			quit_ttf(TTF_Font *font, SDL_Surface *surface)
{
	if (font)
		TTF_CloseFont(font);
	if (surface)
		SDL_FreeSurface(surface);
	TTF_Quit();
}

t_ui_layer					*ui_ttf_to_layer(const char *path, char *txt, \
											t_ui_ttf_param param)
{
	t_ui_layer	*layer;
	TTF_Font	*font;
	SDL_Surface	*surface;

	if (TTF_Init() == -1)
		return (ttf_print_error("Erreur d'initialisation : ", TTF_GetError()));
	if (!(font = TTF_OpenFont(path ? path : "./assets/8bit.ttf", 65)))
	{
		quit_ttf(NULL, NULL);
		return (ttf_print_error("La font est introuvable : ", path));
	}
	if (!(surface = TTF_RenderText_Blended(font, txt, fill_color(param.color))))
	{
		quit_ttf(font, NULL);
		return (ttf_print_error("Erreur dessin de texte : ", TTF_GetError()));
	}
	if (!(layer = ft_memalloc(sizeof(t_ui_layer))))
	{
		quit_ttf(font, surface);
		return (NULL);
	}
	fill_layer(surface, layer, param);
	quit_ttf(font, surface);
	return (layer);
}
