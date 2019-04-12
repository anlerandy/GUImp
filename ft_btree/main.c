#include <stdio.h>
#include <stdlib.h>

#include "ft_btree_rb.h"

void	free_char(void *c)
{
	(void)c;
	return ;
}

int		cmp_char(void *char_a, void *char_b)
{
	return (*(char *)char_a - *(char *)char_b);
}

int		main(void)
{
	int			i;
	t_rb_node	*tree;
	char		*dataset;

	dataset = "0123456789ABCDEFFEDCBA9876543210";
	tree = NULL;
	i = -1;
	while (++i < 16)
	{
		rb_insert(&tree, (void *)(dataset + i), &cmp_char);
		printf("\nfull tree:\n");
		rb_print(tree);
	}
	//i = 0;
	//rb_remove(&tree, (void *)(dataset + i), &cmp_char, &free_char);
	//printf("\nremoving %c:\n", dataset[i]);
	//rb_print(tree);
	printf("clearing ...\n");
	rb_clear_tree(&tree, &free_char);
	printf("cleared ! %p\n", tree);
	while (1);
	return (0);
}
