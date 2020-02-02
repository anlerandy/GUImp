/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:41:19 by alerandy          #+#    #+#             */
/*   Updated: 2019/06/30 17:38:27 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	ft_swap_integer(unsigned nbr)
{
	unsigned short	nb[4];

	nb[0] = (nbr >> 0) & 0xFF;
	nb[1] = (nbr >> 8) & 0xFF;
	nb[2] = (nbr >> 16) & 0xFF;
	nb[3] = (nbr >> 24) & 0xFF;
	nbr = (nb[0] << 24) | (nb[1] << 16) | (nb[2] << 8) | (nb[3] << 0);
	return (nbr);
}
