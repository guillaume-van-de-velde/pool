/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:49:19 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 20:49:31 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	*get_board(char *str)
{
	int	*board;
	int	i;
	int	j;

	i = 0;
	j = 0;
	board = malloc(sizeof(int) * 16);
	if (!board)
		return (NULL);
	while (str[i])
	{
		if (str[i] != ' ')
		{
			board[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (board);
}
