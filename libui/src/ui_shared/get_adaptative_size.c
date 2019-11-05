/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_adaptative_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 06:45:36 by anlerandy         #+#    #+#             */
/*   Updated: 2019/11/05 15:02:12 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "SDL.h"

t_pos       get_adaptative_size(unsigned width, unsigned height)
{
    t_pos                   size;
    SDL_DisplayMode         dm;
    static unsigned char    iter = 0;

    if (SDL_GetCurrentDisplayMode(0, &dm))
        return ((t_pos){(int)width, (int)height});
    ++iter;
    if ((width >= (unsigned)dm.w || width <= 500) && iter < 6)
    {
        size.x = width <= 500 ? 600 : dm.w - 200;
        size.y = size.x * 100. / width / 100. * height;
        return get_adaptative_size((unsigned)size.x, (unsigned)size.y);
    }
    if ((height > (unsigned)dm.h - 350 || height <= 500) && iter < 6)
    {
        size.y = height <= 500 ? 600 : dm.h - 350;
        size.x = size.y * 100. / height / 100. * width;
        return get_adaptative_size((unsigned)size.x, (unsigned)size.y);
    }
    iter = 0;
    return ((t_pos){(int)width, (int)height});
}