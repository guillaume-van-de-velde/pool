/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soluce_found.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:52:12 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/13 16:36:05 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check(int *view, int ask)
{
	int	i;
	int	number;
	int	buildings;

	i = 0;
	number = 0;
	buildings = 0;
	while (i < 4)
	{
		if (number < view[i])
		{
			buildings++;
			number = view[i];
		}
		i++;
	}
	if (ask == buildings)
		return (1);
	return (0);
}

int	compare_for_all_view(int *board, int *soluce, int *view, t_index *index)
{
	index->k = 0;
	index->index_dr = 0;
	if (index->i % 2 == 0)
	{
		while (index->k < 4)
		{
			view[index->k] = soluce[index->j + (index->k * 4)];
			if (index->k == 3 && !check(view, board[index->j + (index->i * 4)]))
				return (0);
			index->k++;
		}
	}
	if (index->i % 2 == 1)
	{
		index->k = 3;
		while (index->k >= 0)
		{
			view[index->index_dr] = soluce[index->k + (index->j * 4)];
			if (index->k == 0 && !check(view, board[index->j + (index->i * 4)]))
				return (0);
			index->index_dr++;
			index->k--;
		}
	}
	return (1);
}

int	check_view(int *board, int *soluce, int *view, t_index *index)
{
	index->j = 0;
	while (index->j < 4)
	{
		if (!compare_for_all_view(board, soluce, view, index))
			return (0);
		index->j++;
	}
	return (1);
}

int	good_view(int *board, int *soluce)
{
	t_index	index;
	int		*view;

	view = malloc(sizeof(int) * 4);
	if (!view)
		return (0);
	index.i = 0;
	while (index.i < 4)
	{
		if (!check_view(board, soluce, view, &index))
			return (free(view), 0);
		index.i++;
	}
	free(view);
	return (1);
}
