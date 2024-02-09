/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:46:03 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 20:46:10 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	left;
	int	right;

	left = 1;
	right = 1;
	if (!root)
		return (0);
	if (root->left)
		left += btree_level_count(root->left);
	if (root->right)
		right += btree_level_count(root->right);
	if (left >= right)
		return (left);
	if (right > left)
		return (right);
	else
		return (1);
}
