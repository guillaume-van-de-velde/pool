/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 07:51:12 by vchakhno          #+#    #+#             */
/*   Updated: 2022/10/05 22:46:11 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_maybe_obstacle	ft_find_obstacle_in_growth(
	t_map map, t_pos pos, int previous_size)
{
	t_pos	corner;
	int		i;

	corner = (t_pos){
		.x = pos.x + previous_size,
		.y = pos.y + previous_size
	};
	if (map.grid[corner.y][corner.x] == map.charset[OBSTACLE_CHAR])
		return ((t_maybe_obstacle){
			.exists = true, .x = corner.x, .y = corner.y});
	i = 0;
	while (i < previous_size)
	{
		if (map.grid[corner.y][pos.x + i] == map.charset[OBSTACLE_CHAR])
			return ((t_maybe_obstacle){
				.exists = true, .x = pos.x + i, .y = corner.y});
		if (map.grid[pos.y + i][corner.x] == map.charset[OBSTACLE_CHAR])
			return ((t_maybe_obstacle){
				.exists = true, .x = corner.x, .y = pos.y + i});
		i++;
	}
	return ((t_maybe_obstacle){.exists = false});
}

void	fill_grey_zone(t_map map, t_pos corner, t_pos obstacle)
{
	int	i;
	int	j;

	i = 0;
	while (i < obstacle.y - corner.y)
	{
		j = 0;
		while (j < obstacle.x - corner.x)
		{
			map.grey_zones[corner.y + i][corner.x + j] = 1;
			j++;
		}
		i++;
	}
}

int	ft_grow_square(t_map map, t_pos pos)
{
	int					square_size;
	t_maybe_obstacle	maybe_obstacle;

	square_size = 0;
	while (
		pos.x + square_size < map.width
		&& pos.y + square_size < map.height)
	{
		maybe_obstacle = ft_find_obstacle_in_growth(map, pos, square_size);
		if (maybe_obstacle.exists)
		{
			fill_grey_zone(map, pos,
				(t_pos){maybe_obstacle.x, maybe_obstacle.y});
			return (square_size);
		}
		square_size++;
	}
	return (square_size);
}

t_square	ft_find_biggest_square(t_map map)
{
	t_square	current;
	t_square	biggest;

	biggest = (t_square){.x = 0, .y = 0, .size = 0};
	current = (t_square){.x = 0, .y = 0};
	while (current.y < map.height - biggest.size)
	{
		if (map.grey_zones[current.y][current.x] == 0)
		{	
			current.size = ft_grow_square(map, (t_pos){current.x, current.y});
			if (current.size > biggest.size)
				biggest = current;
		}
		current.x++;
		if (current.x >= map.width - biggest.size)
		{
			current.x = 0;
			current.y++;
		}
	}
	return (biggest);
}

void	write_square(t_map map, t_square square)
{
	int	i;
	int	j;

	if (square.x < 0 || square.x + square.size - 1 >= map.width)
		return ;
	if (square.y < 0 || square.y + square.size - 1 >= map.height)
		return ;
	i = 0;
	while (i < square.size)
	{
		j = 0;
		while (j < square.size)
		{
			map.grid[square.y + i][square.x + j] = map.charset[SQUARE_CHAR];
			j++;
		}
		i++;
	}
}
