/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:00:01 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/04 19:34:53 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_btree.h"

void	btree_print_node(t_btree *node)
{
	printf("node\tdata: \e[1;34m%d\e[0m\tadr: %p\n", *(int *)node->data, node);
	printf("parent adr: %p\nleft child adr: %p\nright child adr: %p\n\n", \
		node->parent, node->left, node->right);
}

void	btree_print_infix(t_btree *root)
{
	if (!root)
		return ;
	btree_print_infix(root->left);
	btree_print_node(root);
	btree_print_infix(root->right);
}
