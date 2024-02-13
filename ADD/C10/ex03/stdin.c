/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:01:28 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/13 17:15:20 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	while_for_stdin(t_data *data, ssize_t reader)
{
	char	c;
	int		i;

	i = 0;
	reader = read(0, &c, 1);
	if (reader < 0)
		return (-1);
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
		return (0);
	data->input = 1;
	return (1);
}

void	for_stdin(t_data *data)
{
	ssize_t	reader;
	int		return_value;

	reader = 1;
	while (1)
	{
		return_value = while_for_stdin(data, reader);
		if (return_value == -1)
			return ;
		if (!return_value)
			break ;
	}
	if (data->input)
	{
		display_number_octets(data->octets, data->option);
		ft_putchar('\n');
	}
}
