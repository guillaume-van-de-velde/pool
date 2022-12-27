/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 06:57:50 by vchakhno          #+#    #+#             */
/*   Updated: 2022/10/05 23:08:34 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	bsq_from_file(char *filename)
{
	int			fileno;
	t_maybe_map	maybe_map;
	t_square	biggest_square;

	fileno = open(filename, O_RDONLY);
	if (fileno == -1)
	{
		ft_putstr_err("map error\n");
		return ;
	}
	maybe_map = create_map(fileno);
	close(fileno);
	if (maybe_map.exists)
	{
		biggest_square = ft_find_biggest_square(maybe_map.map);
		write_square(maybe_map.map, biggest_square);
		display_map(maybe_map.map);
		free_map(maybe_map.map);
	}
}

void	bsq_from_stdin(void)
{
	t_maybe_map	maybe_map;
	t_square	biggest_square;

	maybe_map = create_map(STDIN_FILENO);
	if (maybe_map.exists)
	{
		biggest_square = ft_find_biggest_square(maybe_map.map);
		write_square(maybe_map.map, biggest_square);
		display_map(maybe_map.map);
		free_map(maybe_map.map);
	}
}

int	main(int argc, char **argv)
{
	int			i;

	if (argc == 1)
	{
		bsq_from_stdin();
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			bsq_from_file(argv[i]);
			i++;
		}		
	}
}
