/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_pix_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:35:24 by alerandy          #+#    #+#             */
/*   Updated: 2019/10/11 17:40:23 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_shared.h"
#include <math.h>

t_argb		ui_argb_addition(t_argb a, t_argb b)
{
	a.a += b.a;
	a.r += b.r;
	a.g += b.g;
	a.b += b.b;
	return (a);
}

t_argb		ui_argb_substract(t_argb a, t_argb b)
{
	a.a -= b.a;
	a.r -= b.r;
	a.g -= b.g;
	a.b -= b.b;
	return (a);
}

t_argb		ui_argb_average(t_argb a, t_argb b)
{
	double	subs[4];

	subs[0] = (a.r + b.r);
	subs[1] = (a.g + b.g);
	subs[2] = (a.b + b.b);
	subs[3] = (a.a + b.a);
	a.r += (unsigned char)ceil(subs[0] / 2);
	a.g += (unsigned char)ceil(subs[1] / 2);
	a.b += (unsigned char)ceil(subs[2] / 2);
	a.a += (unsigned char)ceil(subs[3] / 2);
	return (a);
}

t_bgra		ui_bgra_addition(t_bgra a, t_bgra b)
{
	a.a += b.a;
	a.r += b.r;
	a.g += b.g;
	a.b += b.b;
	return (a);
}

t_bgra		ui_bgra_substract(t_bgra a, t_bgra b)
{
	a.a -= b.a;
	a.r -= b.r;
	a.g -= b.g;
	a.b -= b.b;
	return (a);
}