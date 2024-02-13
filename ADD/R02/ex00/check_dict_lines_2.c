/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict_lines_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:39:32 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/13 17:39:35 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	keep_only_translate(t_data *data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (data->dict[i])
	{
		j = 0;
		while (data->dict[i][j] >= '0' && data->dict[i][j] <= '9')
			j++;
		while (data->dict[i][j] == ' ')
			j++;
		j++;
		while (data->dict[i][j] == ' ')
			j++;
		str = ft_strdup(&data->dict[i][j]);
		if (!str)
			return (free_split(data->dict));
		free(data->dict[i]);
		data->dict[i] = str;
		i++;
	}
}

void	free_other_data(char **dict, int len)
{
	while (len > 40)
	{
		free(dict[len]);
		dict[len] = NULL;
		len--;
	}
}

void	swap_string(char **dict, int i, int j)
{
	char	*tmp;

	tmp = dict[i];
	dict[i] = dict[j];
	dict[j] = tmp;
}

int	good_number_for_place(char *str_dict, char *good)
{
	size_t	i;

	i = 0;
	while (str_dict[i] && good[i])
	{
		if ((unsigned char)str_dict[i] - (unsigned char)good[i] != 0)
			return (0);
		i++;
	}
	if (good[i])
	{
		return (0);
	}
	if (str_dict[i] == ' ' || str_dict[i] == ':')
		return (1);
	return (0);
}

char	*thousand_plus(int place)
{
	if (place == 29)
		return ("1000");
	if (place == 30)
		return ("1000000");
	if (place == 31)
		return ("1000000000");
	if (place == 32)
		return ("1000000000000");
	if (place == 33)
		return ("1000000000000000");
	if (place == 34)
		return ("1000000000000000000");
	if (place == 35)
		return ("1000000000000000000000");
	if (place == 36)
		return ("1000000000000000000000000");
	if (place == 37)
		return ("1000000000000000000000000000");
	if (place == 38)
		return ("1000000000000000000000000000000");
	if (place == 39)
		return ("1000000000000000000000000000000000");
	if (place == 40)
		return ("1000000000000000000000000000000000000");
	return (NULL);
}
