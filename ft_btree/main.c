#include <stdio.h>
#include <stdlib.h>

#include "ft_btree_rb.h"

int		cmp_char(void *char_a, void *char_b)
{
	return (*(char *)char_a - *(char *)char_b);
}

int		main(void)
{
	t_rb_node	*tree;
	char		*dataset;

	dataset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	tree = NULL;
	rb_insert(&tree, dataset + 3, &cmp_char);
	rb_insert(&tree, dataset + 4, &cmp_char);
	rb_insert(&tree, dataset + 5, &cmp_char);
	rb_insert(&tree, dataset + 1, &cmp_char);
	rb_insert(&tree, dataset + 0, &cmp_char);
	rb_insert(&tree, dataset + 2, &cmp_char);
	rb_insert(&tree, dataset + 10, &cmp_char);
	rb_insert(&tree, dataset + 7, &cmp_char);
	printf("\nrb print:\n");
	rb_print(tree);
	return (0);
}

/*
#include "ft_btree.h"
void	btree_print_node(void *data)
{
	if (!data)
		return ;
	printf("node:\t%c\n", *(char *)data);
}

int		cmp_char(void *char_a, void *char_b)
{
	return (*(char *)char_a - *(char *)char_b);
}

void	print_lvl(void *item, int curr_lvl, int first_elem)
{
	if (!item)
		return ;
	printf("node:\t%c\tlevel:\t%d\tfirst:\t%d\n", *(char*)item, curr_lvl, first_elem);
}

int		main(void)
{
	t_btree		*tree;
	char		dataset[6];

	dataset[0] = 'A';
	dataset[1] = 'B';
	dataset[2] = 'C';
	dataset[3] = 'D';
	dataset[4] = 'E';
	dataset[5] = 'F';
	tree = NULL;
	btree_insert_data(&tree, dataset + 3, &cmp_char);
	btree_insert_data(&tree, dataset + 4, &cmp_char);
	btree_insert_data(&tree, dataset + 5, &cmp_char);
	btree_insert_data(&tree, dataset + 1, &cmp_char);
	btree_insert_data(&tree, dataset + 0, &cmp_char);
	btree_insert_data(&tree, dataset + 2, &cmp_char);
	printf("Parcours prefix:\n");
	btree_apply_prefix(tree, btree_print_node);
	printf("\nParcours suffix:\n");
	btree_apply_suffix(tree, btree_print_node);
	printf("\nParcours infix:\n");
	btree_apply_infix(tree, btree_print_node);
	printf("\nParcours apply by level:\n");
	btree_apply_by_level(tree, print_lvl);
	printf("\nbtre print:\n");
	btree_print(tree);
	free(tree->right);
	free(tree->left);
	free(tree);
	return (0);
}
*/
