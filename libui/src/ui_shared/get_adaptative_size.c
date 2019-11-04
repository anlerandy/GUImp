/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_adaptative_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 06:45:36 by anlerandy         #+#    #+#             */
/*   Updated: 2019/11/04 07:18:47 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "SDL.h"

t_pos       get_adaptative_size(unsigned width, unsigned height)
{
    t_pos               size;
    SDL_DisplayMode     dm;

    SDL_GetCurrentDisplayMode(0, &dm);
    if (width >= (unsigned)dm.w)
    {
        size.x = dm.w - 200;
        size.y = size.x * 100. / width / 100. * height;
        return get_adaptative_size((unsigned)size.x, (unsigned)size.y);
    }
    if (height >= (unsigned)dm.h)
    {
        size.y = dm.h - 200;
        size.x = size.y * 100. / height / 100. * width;
        return get_adaptative_size((unsigned)size.x, (unsigned)size.y);
    }
    return ((t_pos){(unsigned)width, (unsigned)height});
}