/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_delpng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 18:49:06 by alerandy          #+#    #+#             */
/*   Updated: 2019/06/30 21:01:45 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png.h"

void	ui_delpng(t_png *png)
{
	free(png->palette);
	free(png->opacity);
	free(png->pixels);
	free(png->raw_data);
	ft_bzero(png, sizeof(t_png));
}
