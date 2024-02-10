/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:45:18 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/10 19:03:20 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
int (*cmpf)(void *, void *))
{
	t_btree	*btree;

	if (root->left)
	{
		btree = btree_search_item(root->left, data_ref, (*cmpf));
		if (btree)
			return (btree);
	}
	if (!(*cmpf)(data_ref, root->item))
		return (root);
	if (root->right)
	{
		btree = btree_search_item(root->right, data_ref, (*cmpf));
		if (btree)
			return (btree);
	}
	return (NULL);
}
