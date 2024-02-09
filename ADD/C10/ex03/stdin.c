/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:01:28 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 20:01:43 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	for_stdin(t_data *data)
{
	char	c;
	int		i;
	ssize_t	reader;

	i = 0;
	reader = 1;
	while (1)
	{
		reader = read(0, &c, 1);
		if (reader < 0)
			return ;
		if (reader == 0)
			data->str[i] = '\0';
		else
			data->str[i] = c;
		if (i == 15 || reader == 0)
		{
			result_management(data);
			data->octets += ft_strlen(data->str);
			i = 0;
		}
		else
			i++;
		if (reader == 0)
			break ;
		data->input = 1;
	}
	if (data->input)
	{
		display_number_octets(data->octets, data->option);
		ft_putchar('\n');
	}
}
