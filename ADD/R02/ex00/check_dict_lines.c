/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:56:37 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/13 17:52:47 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*value_ref(int place)
{
	if (place <= 20)
		return (ft_itoa(place));
	if (place > 20 && place < 28)
		return (ft_itoa((place - 20) * 10 + 20));
	if (place == 28)
		return (ft_itoa(100));
	if (place > 28)
		return (ft_strdup(thousand_plus(place)));
	return (NULL);
}

int	search_swapper(char **dict, int i)
{
	int		j;
	char	*good_number;

	j = i;
	good_number = value_ref(i);
	if (!good_number)
		return (-1);
	while (dict[j])
	{
		if (good_number_for_place(dict[j], good_number))
			return (free(good_number), j);
		j++;
	}
	free(good_number);
	return (-1);
}

int	good_place(char *str, int i, int *error)
{
	char	*good_number;

	if (i > 40)
		return (1);
	good_number = value_ref(i);
	if (!good_number)
		return (*error = 1, 0);
	if (!good_number_for_place(str, good_number))
		return (free(good_number), 0);
	free(good_number);
	return (1);
}

int	while_for_check_dict_line(t_data *data, int *i)
{
	int	j;

	*i = 0;
	while (data->dict[*i])
	{
		if (!good_place(data->dict[*i], *i, &data->error))
		{
			if (data->error != 0)
				return (free_split(data->dict), (void)print_error(), 0);
			j = search_swapper(data->dict, *i);
			if (j == -1)
				return (free_split(data->dict), data->error = 1,
					(void)print_dict_error(), 0);
			swap_string(data->dict, *i, j);
		}
		(*i)++;
	}
	return (1);
}

void	check_dict_lines(t_data *data)
{
	int	i;

	i = 0;
	while (data->dict[i])
	{
		if (!good_line(data->dict[i]))
			return (free_split(data->dict), data->error = 1,
				(void)print_dict_error());
		i++;
	}
	if (!while_for_check_dict_line(data, &i))
		return ;
	free_other_data(data->dict, i);
	keep_only_translate(data);
	if (data->error != 0)
		return (free_split(data->dict), data->error = 1, (void)print_error());
}
