/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:10:07 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 15:10:30 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	bsq_for_file(t_data *data)
{
	int	i;

	i = 0;
	while (data->fds[i])
	{
		if (i != 0)
			write(1, "\n", 1);
		if (data->fds[i] != -1)
		{
			parsing(data, i);
			if (!data->error)
				resolve(data);
			free_map(data);
			data->error = 0;
		}
		else
			print_error();
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	set_data(&data);
	check_args(argc, argv, &data);
	if (data.fds)
		bsq_for_file(&data);
	else
	{
		parsing(&data, -2);
		if (!data.error)
			resolve(&data);
	}
	free_all(&data);
}
