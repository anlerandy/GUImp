/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_memuset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:41:12 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/23 16:49:09 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ui_memuset(void *b, unsigned c, size_t len)
{
	size_t		i;
	unsigned	*dst;

	if (!b)
		return ;
	dst = b;
	i = 0;
	while (i < len)
		dst[i++] = c;
}
