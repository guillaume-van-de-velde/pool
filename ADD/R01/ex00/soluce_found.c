/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soluce_found.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:52:12 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 20:52:37 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_good_buildings(int *view, int ask)
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

int	good_view(int *board, int *soluce)
{
	int	i;
	int	j;
	int	k;
	int	index_dr;
	int	*view;

	view = malloc(sizeof(int) * 4);
	if (!view)
		return (0);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			index_dr = 0;
			if (i == 0)
			{
				while (k < 4)
				{
					view[k] = soluce[j + (k * 4)];
					if (k == 3 && !check_good_buildings(view, board[j + (i * 4)]))
						return (free(view), 0);
					k++;
				}
			}
			if (i == 1)
			{
				k = 3;
				while (k >= 0)
				{
					view[index_dr] = soluce[j + (k * 4)];
					if (k == 0 && !check_good_buildings(view, board[j + (i * 4)]))
						return (free(view), 0);
					index_dr++;
					k--;
				}
			}
			if (i == 2)
			{
				while (k < 4)
				{
					view[k] = soluce[k + (j * 4)];
					if (k == 3 && !check_good_buildings(view, board[j + (i * 4)]))
						return (free(view), 0);
					k++;
				}
			}
			if (i == 3)
			{
				k = 3;
				while (k >= 0)
				{
					view[index_dr] = soluce[k + (j * 4)];
					if (k == 0 && !check_good_buildings(view, board[j + (i * 4)]))
						return (free(view), 0);
					index_dr++;
					k--;
				}
			}
			j++;
		}
		i++;
	}
	free(view);
	return (1);
}
