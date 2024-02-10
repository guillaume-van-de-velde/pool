/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:14:20 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/10 17:00:49 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*replace_line(t_data *data, t_square biggest)
{
	char			*map_result;
	t_coordinate	stock;
	int				len;

	len = ft_strlen(data->map[1]) + 1;
	map_result = &data->file[ft_strlen(data->map[0]) + 1];
	stock.line = biggest.spot.line;
	stock.column = biggest.spot.column;
	while (biggest.spot.line < biggest.size + stock.line)
	{
		biggest.spot.column = stock.column;
		while (biggest.spot.column < biggest.size + stock.column)
		{
			map_result[biggest.spot.line * len
				+ biggest.spot.column] = data->chars.full;
			biggest.spot.column++;
		}
		biggest.spot.line++;
	}
	return (map_result);
}

void	fill_square(t_square *square)
{
	square->spot.line = 0;
	square->spot.column = 0;
	square->size = 0;
}

t_square	resolve_loop(t_chars *chars, t_square biggest, char **map)
{
	t_coordinate	current;
	t_square		new;
	int				count;

	count = 0;
	current.line = 0;
	while (map[current.line])
	{
		current.column = 0;
		while (map[current.line][current.column])
		{
			if (map[current.line][current.column] == chars->nul)
			{
				count++;
				new = calcul_square(map, current, chars);
				if (new.size > biggest.size)
					biggest = new;
			}
			current.column++;
		}
		current.line++;
	}
	return (biggest);
}

void	resolve(t_data *data)
{
	t_square	biggest;

	fill_square(&biggest);
	biggest = resolve_loop(&data->chars, biggest, &data->map[1]);
	print_map(replace_line(data, biggest));
}
