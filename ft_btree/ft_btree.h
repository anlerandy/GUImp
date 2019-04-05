/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:12:23 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/05 22:31:02 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef	struct	s_btree
{
	struct s_btree		*parent;
	struct s_btree		*left;
	struct s_btree		*right;
	void				*data;
}				t_btree;

/*
** fonctions du sujet de la piscine C (good old times...)
*/

t_btree			*btree_new_node(void *data);
void			btree_apply_prefix(t_btree *root, void (*node_funct)(void *));
void			btree_apply_infix(t_btree *root, void (*node_funct)(void *));
void			btree_apply_suffix(t_btree *root, void (*node_funct)(void *));
void			btree_insert_data(t_btree **root, void *item, \
					int (*cmp_funct)(void *, void *));
void			*btree_search_infix(t_btree *root, void *data_ref, \
					int (*cmp_funct)(void *, void *));
int				btree_level_count(t_btree *root);
void			btree_apply_by_level(t_btree *root, \
					void (*node_funct)(void *item, int current_level, \
						int is_first_elem));

#endif
