/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:56:55 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 21:17:39 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	set_data(t_data *data)
{
	data->dict = NULL;
	data->number = NULL;
	data->error = 0;
	data->writted = 0;
	data->no_print = 0;
}

void	parsing(int argc, char **argv, t_data *data)
{
	set_data(data);
	check_args(argc, argv, data);
	if (data->error != 0)
		return ;
	if (argc == 3)
		parse_dict(data, argv[1]);
	else
		create_dict(data);
}
