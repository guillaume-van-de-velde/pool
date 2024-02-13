/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:57:00 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/13 17:27:27 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	decremente_incremente(int *len, int *i)
{
	(*len)--;
	(*i)++;
}

void	recursive_resolve(t_data *data, int len, int i)
{
	if (data->number[i] == '0' && !(len == 1 && i == 0))
		decremente_incremente(&len, &i);
	if (len % 3 == 0)
	{
		hundreds(data, i);
		decremente_incremente(&len, &i);
	}
	if (data->number[i] == '0' && !(len == 1 && i == 0))
		decremente_incremente(&len, &i);
	if (len % 3 == 2)
	{
		tens(data, i);
		decremente_incremente(&len, &i);
	}
	if (data->number[i] == '0' && !(len == 1 && i == 0))
		decremente_incremente(&len, &i);
	if (len % 3 == 1)
		(units(data, i, len), len--, i++);
	if (len != 0 && !data->no_print)
		greatness(data, len);
	if (len == 0)
		return ;
	recursive_resolve(data, len, i);
}

void	resolve(t_data *data)
{
	int	len;

	len = ft_strlen(data->number);
	data->no_print = 1;
	recursive_resolve(data, len, 0);
	write(1, "\n", 1);
}
