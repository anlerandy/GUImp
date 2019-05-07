/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_png.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:23:59 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/07 19:37:57 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_PNG_H
# define UI_PNG_H

# include "libui.h"
# include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef enum                                e_cformat
{
    RGBA,
    ARGB,
    GRAYA,
    AGRAY,
    INDEXA,
    AINDEX
}                                           t_cformat;

typedef struct __attribute__((__packed__))  s_png
{
    unsigned char   signature[9];
    unsigned        width;
    unsigned        height;
    unsigned        *pixels;
    t_cformat       format;
}                                           t_png;

t_png                                       ui_getpng(char *path);
void                                       	ui_putpng(t_png png);
int                                         validate_png(t_png png);

#endif