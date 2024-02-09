/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soluce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:52:51 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 20:53:03 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	back_tracking(int *board, int *soluce, int advance)
{
	int	i;

	i = 1;
	advance++;
	if (advance == 16)
	{
		if (good_view(board, soluce))
			return (print_soluce(soluce, soluce_found()));
		return ;
	}
	while (i < 5)
	{
		if (good_number(soluce, advance, i))
		{
			back_tracking(board, soluce, advance);
			soluce[advance] = 0;
		}
		i++;
	}
	return ;
}

void	set_soluce(int *soluce)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		soluce[i] = 0;
		i++;
	}
}

void	start_soluce(int *board)
{
	int	*soluce;

	soluce = malloc(sizeof(int) * 16);
	if (!soluce)
		return ;
	set_soluce(soluce);
	back_tracking(board, soluce, -1);
	free(board);
	free(soluce);
}
