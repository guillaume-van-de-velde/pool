/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:46:47 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/10 19:03:32 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_by_level(t_btree *root,
void (*applyf)(void *item, int current_level, int is_first_elem))
{
	static int	level = -1;

	level++;
	if (!root)
		return ;
	(*applyf)(root->item, level, (level == 0));
	if (root->left)
		btree_apply_by_level(root->left, (*applyf));
	if (root->right)
		btree_apply_by_level(root->right, (*applyf));
	level--;
}
