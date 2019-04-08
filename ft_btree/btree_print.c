/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:42:22 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/07 17:39:46 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_btree.h"

static void		print_node(int lvl, t_btree *node)
{
	int		i;

	if (!node)
		return ;
	i = 0;
	while (i++ < lvl)
		printf("  |");
	printf("->%c\n", *(char *)(node->data));
	print_node(lvl + 1, node->left);
	print_node(lvl + 1, node->right);
}

void			btree_print(t_btree *root)
{
	print_node(0, root);
}
