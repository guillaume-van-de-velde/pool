/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:57:17 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 19:57:25 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	fill_data(t_data *data, int argc, char **argv)
{
	data->str = malloc(17);
	if (!data->str)
		return ;
	if (argc == 1)
		return (data->stdin = 1, (void)0);
	if (!ft_strncmp(argv[1], "-C", 3))
	{
		data->option = 1;
		if (argv[2])
			data->files = &argv[2];
		else
			data->stdin = 1;
	}
	else
		data->files = &argv[1];
}

void	set_data(t_data *data)
{
	data->option = 0;
	data->str = NULL;
	data->files = NULL;
	data->fd = 0;
	data->stdin = 0;
	data->octets = 0;
	data->link = 0;
	data->input = 0;
}
