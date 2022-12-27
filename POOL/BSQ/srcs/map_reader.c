/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:51:30 by vchakhno          #+#    #+#             */
/*   Updated: 2022/10/05 23:36:10 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	positive_atoi(char *str, int *i)
{
	int	value;

	value = 0;
	while ('0' <= str[*i] && str[*i] <= '9')
	{
		value = 10 * value + str[*i] - '0';
		(*i)++;
	}
	return (value);
}

bool	read_first_line(int fileno, t_map *map)
{
	t_resizable_str	line;
	int				i;

	line = get_line(fileno);
	i = 0;
	if (line.str[0] < '0' || '9' < line.str[0])
	{
		ft_putstr_err("map error\n");
		free(line.str);
		return (false);
	}
	map->height = positive_atoi(line.str, &i);
	if (map->height <= 0 || line.size != i + 3)
	{
		ft_putstr_err("map error\n");
		free(line.str);
		return (false);
	}
	map->charset[EMPTY_CHAR] = line.str[i++];
	map->charset[OBSTACLE_CHAR] = line.str[i++];
	map->charset[SQUARE_CHAR] = line.str[i++];
	free(line.str);
	if (!check_chars(map->charset))
		return (false);
	return (true);
}

bool	check_map_char(char *line, t_map map)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != map.charset[OBSTACLE_CHAR]
			&& line[i] != map.charset[EMPTY_CHAR])
		{
			ft_putstr_err("map error\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	read_first_map_line(int fileno, t_map *map)
{
	t_resizable_str	line;

	line = get_line(fileno);
	if (line.size == 0)
	{
		ft_putstr_err("map error\n");
		return (false);
	}
	if (!check_map_char(line.str, *map))
		return (false);
	map->width = line.size;
	map->grid = malloc(sizeof(char *) * (map->height));
	if (!map->grid)
	{
		ft_putstr_err("map error\n");
		return (false);
	}
	map->grid[0] = line.str;
	return (true);
}

bool	read_other_map_lines(int fileno, t_map *map)
{
	t_resizable_str	line;
	int				i;

	i = 1;
	while (i < map->height)
	{
		line = get_line(fileno);
		map->grid[i] = line.str;
		if (line.size != map->width)
		{
			ft_putstr_err("map error\n");
			return (false);
		}
		if (!check_map_char(line.str, *map))
		{
			return (false);
		}
		i++;
	}
	return (true);
}
