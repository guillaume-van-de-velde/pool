/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 05:16:23 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/29 05:21:10 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_bonnecombinaison(int *board, int *sol)
{
	int	i;
	int	value;

	i = 0;
	while (i < 10)
	{
		value = board[i] + 48;
		write(1, &value, 1);
		i++;
	}
	write(1, "\n", 1);
	(*sol)++;
}

int	ft_true(int *board, int pos)
{
	int	i;
	int	diff;

	i = 0;
	while (i < pos)
	{
		diff = board[i] - board[pos];
		if (diff < 0)
			diff *= -1;
		if (!(diff) || pos - i == diff)
			return (0);
		i++;
	}
	return (1);
}

int	queen_algo(int pos, int *sol, int *board)
{
	int	i;

	i = 0;
	if (pos == 10)
	{
		ft_bonnecombinaison(board, sol);
		return (1);
	}
	while (i < 10)
	{
		board[pos] = i;
		if (ft_true(board, pos))
			queen_algo(pos + 1, sol, board);
		i++;
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int	sol;
	int	i;
	int	board[10];

	sol = 0;
	i = 0;
	while (i < 10)
		board[i++] = 0;
	queen_algo(0, &sol, board);
	return (sol);
}
