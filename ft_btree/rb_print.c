/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:40:29 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/08 17:55:06 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_btree_rb.h"

static void		print_node(int lvl, t_rb_node *node)
{
	char	data;
	char	*color;
	int		i;

	if (node)
	{
		data = *(char *)(node->data);
		color = (node->color == RB_RED ? "\x1B[31m" : "\x1B[32m");
	}
	else
	{
		data = ' ';
		color = "\x1B[32m";
	}
	i = 0;
	while (i++ < lvl)
		printf("  |");
	printf("->%s%c\x1B[0m\n", color, data);
	if (!node)
		return ;
	print_node(lvl + 1, node->left);
	print_node(lvl + 1, node->right);
}

void			rb_print(t_rb_node *root)
{
	print_node(0, root);
	printf("\n");
}
