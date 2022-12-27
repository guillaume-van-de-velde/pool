/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:26:03 by vchakhno          #+#    #+#             */
/*   Updated: 2022/10/05 22:45:26 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_tab_n(char **grid, char height)
{
	int	i;

	i = 0;
	while (i < height && grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

char	**create_empty_grid(int width, int height)
{
	int		i;
	int		j;
	char	**grid;

	grid = malloc(sizeof(char *) * height);
	if (!grid)
		return (NULL);
	i = 0;
	while (i < height)
	{
		grid[i] = malloc(sizeof(char *) * width);
		if (!grid)
		{
			free_tab_n(grid, height);
			return (NULL);
		}
		j = 0;
		while (j < width)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (grid);
}

t_maybe_map	create_map(int fileno)
{
	t_map			map;

	map.grid = NULL;
	map.grey_zones = NULL;
	if (!read_first_line(fileno, &map))
		return ((t_maybe_map){.exists = false});
	if (!read_first_map_line(fileno, &map))
	{
		free_tab_n(map.grid, map.height);
		return ((t_maybe_map){.exists = false});
	}
	if (!read_other_map_lines(fileno, &map))
	{
		free_tab_n(map.grid, map.height);
		return ((t_maybe_map){.exists = false});
	}
	map.grey_zones = create_empty_grid(map.width, map.height);
	if (!map.grey_zones)
	{
		return ((t_maybe_map){.exists = false});
	}
	return ((t_maybe_map){.exists = true, .map = map});
}

void	display_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.height)
	{
		ft_putstr(map.grid[i]);
		write(1, "\n", 1);
		i++;
	}
}

void	free_map(t_map map)
{
	free_tab_n(map.grid, map.height);
	free_tab_n(map.grey_zones, map.height);
}
