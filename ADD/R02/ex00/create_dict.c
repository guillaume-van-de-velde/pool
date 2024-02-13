/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:56:39 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/13 17:35:33 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	create_dict(t_data *data)
{
	int	i;

	i = 0;
	data->dict = malloc(sizeof(char *) * 42);
	if (!data->dict)
		return (data->error = 1, (void)print_error());
	while (i < 41)
	{
		data->dict[i] = fill_dict_create(i);
		i++;
	}
	data->dict[i] = NULL;
}
