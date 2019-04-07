/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_parenting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:06:43 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/07 15:17:55 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_btree_rb.h"

t_rb_node	*grand_father(t_rb_node *node)
{
	t_rb_node	*father;

	father = node->parent;
	if (!father)
		return (NULL);
	return (father->parent);
}

t_rb_node	*brother(t_rb_node *node)
{
	t_rb_node	*father;

	father = node->parent;
	if (!father)
		return (NULL);
	if (node == father->left)
		return (father->right);
	return (father->left);
}

t_rb_node	*uncle(t_rb_node *node)
{
	t_rb_node	*father;
	t_rb_node	*gra_father;

	father = node->parent;
	gra_father = grand_father(node);
	if (!gra_father)
		return (NULL);
	return (brother(father));
}
