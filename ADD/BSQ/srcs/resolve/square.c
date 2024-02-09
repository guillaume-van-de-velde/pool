/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:15:42 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 15:16:08 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_line_and_column(char **map, t_coordinate current, t_coordinate stock, t_chars *chars)
{
	int	stock_index;

	stock_index = current.column;
	while (current.column >= stock.column)
	{
		if (map[current.line][current.column] == chars->barrier)
		{
			fill_grey(map, stock, current, chars->barrier);
			return (0);
		}
		current.column--;
	}
	while (current.line >= stock.line)
	{
		if (map[current.line][stock_index] == chars->barrier)
		{
			fill_grey(map, stock, (t_coordinate){current.line, stock_index}, chars->barrier);
			return (0);
		}
		current.line--;
	}
	return (1);
}

t_square	calcul_square(char **map, t_coordinate current, t_chars *chars)
{
	t_coordinate	stock;
	int				size;

	stock.column = current.column;
	stock.line = current.line;
	size = 0;
	while (map[current.line])
	{
		if (map[current.line][current.column])
		{
			if (!check_line_and_column(map, current, stock, chars))
				break ;
		}
		else
			break ;
		size++;
		current.column++;
		current.line++;
	}
	return ((t_square){stock, size});
}
