/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_pix_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:35:24 by alerandy          #+#    #+#             */
/*   Updated: 2019/11/13 14:30:35 by alerandy         ###   ########.fr       */
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
	a.r = (floor((a.r + b.r) / 2.));
	a.g = (floor((a.g + b.g) / 2.));
	a.b = (floor((a.b + b.b) / 2.));
	a.a = (floor((a.a + b.a) / 2.));
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
