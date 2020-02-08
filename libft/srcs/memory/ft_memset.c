/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:28:09 by alerandy          #+#    #+#             */
/*   Updated: 2020/02/03 13:36:22 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	ft_memfill(unsigned long *dstp, unsigned long c, size_t len)
{
	unsigned long	*source;

	while (--len > 0)
	{
		source = (unsigned long*)*dstp;
		source[0] = c;
		source[1] = c;
		source[2] = c;
		source[3] = c;
		source[4] = c;
		source[5] = c;
		source[6] = c;
		source[7] = c;
		*dstp += 8 * sizeof(long);
	}
}

static inline void	ft_memfillrest(unsigned long *dstp, unsigned long c, \
		size_t len)
{
	while (--len > 0)
	{
		*((unsigned long *)*dstp) = c;
		*dstp += sizeof(long);
	}
}

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned long	dstp;
	unsigned long	cccc;

	dstp = (unsigned long)b;
	if (len >= 8)
	{
		cccc = (unsigned char)c;
		cccc |= cccc << 8;
		cccc |= cccc << 16;
		cccc |= (cccc << 16) << 16;
		while (dstp % sizeof(long) != 0 && len--)
			*((unsigned char *)dstp++) = c;
		ft_memfill(&dstp, cccc, len / (sizeof(long) * 8) + 1);
		len %= sizeof(long) * 8;
		ft_memfillrest(&dstp, cccc, len / sizeof(long) + 1);
		len %= sizeof(long);
	}
	while (len-- > 0)
		*((unsigned char *)dstp++) = c;
	return (b);
}
