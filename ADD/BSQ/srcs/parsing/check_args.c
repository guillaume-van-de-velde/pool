/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:11:04 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 15:11:18 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	check_args(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	if (argc < 2)
		return ;
	data->fds = malloc(sizeof(int) * argc);
	if (!data->fds)
		exit(1);
	data->fds[argc - 1] = 0;
	while (i < argc - 1)
	{
		data->fds[i] = open(argv[i + 1], O_RDONLY);
		i++;
	}
}
