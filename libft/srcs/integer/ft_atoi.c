/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:08:26 by alerandy          #+#    #+#             */
/*   Updated: 2020/09/09 19:34:13 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		nb;
	size_t	sign;

	sign = 0;
	nb = 0;
	while (ft_isspace(*str) == 1)
		str++;
	*str == '-' ? --sign : ++sign;
	str = *str == '-' || *str == '+' ? str + 1 : str;
	while (*str && *str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += (*str - 48);
		++str;
	}
	return (nb * sign);
}
