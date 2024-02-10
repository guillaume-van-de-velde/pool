/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:44:27 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/10 19:03:45 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
int (*cmpf)(void *, void *))
{
	t_btree	*btree;

	if (!root)
		return ;
	if (!*root)
		return (*root = btree_create_node(item), (void)0);
	btree = *root;
	if ((*cmpf)(item, btree->item) < 0)
		btree_insert_data(&btree->left, item, (*cmpf));
	else
		btree_insert_data(&btree->right, item, (*cmpf));
}
