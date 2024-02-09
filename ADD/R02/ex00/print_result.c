/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:56:57 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 21:18:16 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	hundreds(t_data *data, int index)
{
	if (data->number[index] == '0')
		return ;
	if (data->writted == 1)
		(write(1, " ", 1), data->writted = 0);
	write(1, data->dict[data->number[index] - '0'], ft_strlen(data->dict[data->number[index] - '0']));
	write(1, " ", 1);
	write(1, data->dict[28], ft_strlen(data->dict[28]));
	data->writted = 1;
	data->no_print = 0;
}

void	tens(t_data *data, int index)
{
	if (data->number[index] == '0')
		return ;
	if (data->writted == 1)
		(write(1, " ", 1), data->writted = 0);
	if (data->number[index] == '1')
		write(1, data->dict[10 + data->number[index + 1] - '0'], ft_strlen(data->dict[10 + data->number[index + 1] - '0']));
	else
		write(1, data->dict[20 + (data->number[index] - '0' - 2)], ft_strlen(data->dict[20 + (data->number[index] - '0' - 2)]));
	data->writted = 1;
	data->no_print = 0;
}

void	units(t_data *data, int index, int len)
{
	if (data->number[index] == '0' && !(len == 1 && index == 0))
		return ;
	if (index != 0 && data->number[index - 1] == '1')
		return ;
	if (data->writted == 1)
		(write(1, " ", 1), data->writted = 0);
	write(1, data->dict[data->number[index] - '0'], ft_strlen(data->dict[data->number[index] - '0']));
	data->writted = 1;
	data->no_print = 0;
}

void	greatness(t_data *data, int len)
{
	if (data->writted == 1)
		(write(1, " ", 1), data->writted = 0);
	write(1, data->dict[29 + ((len - 1) / 3)], ft_strlen(data->dict[29 + ((len - 1) / 3)]));
	data->writted = 1;
	data->no_print = 1;
}
