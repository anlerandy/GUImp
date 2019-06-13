/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_search_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:05:22 by gsmith            #+#    #+#             */
/*   Updated: 2019/06/13 14:43:01 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_btree_rb.h"

static unsigned int	count_node(t_rb_node *node, void *data_ref, \
						int (*cmp_funct)(void *, void *))
{
	unsigned int	res;

	res = 0;
	if (node->left)
		res += count_node(node->left, data_ref, cmp_funct);
	if (node->right)
		res += count_node(node->right, data_ref, cmp_funct);
	if (!cmp_funct(node->data, data_ref))
		res++;
	return (res);
}

static unsigned int	fill_tab(void **tab, t_rb_node *node, void *data_ref, \
						int (*cmp_funct)(void *, void *))
{
	unsigned int	i;

	i = 0;
	if (!cmp_funct(node->data, data_ref))
		tab[i++] = node->data;
	if (node->left)
		i += fill_tab(tab + i, node->left, data_ref, cmp_funct);
	if (node->right)
		i += fill_tab(tab + i, node->right, data_ref, cmp_funct);
	return (i);
}

void				**rb_search_all(t_rb_node *root, void *data_ref, \
						int (*cmp_funct)(void *, void *))
{
	unsigned int	count;
	void			**tab;

	if (!root || !(count = count_node(root, data_ref, cmp_funct)))
		return (NULL);
	if (!(tab = ft_memalloc(sizeof(void *) * count + 1)))
		return (NULL);
	fill_tab(tab, root, data_ref, cmp_funct);
	return (tab);
}
