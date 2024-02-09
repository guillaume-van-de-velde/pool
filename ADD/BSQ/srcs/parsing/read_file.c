/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:12:51 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 15:27:26 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_realloc(char *str, int advance)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(advance + 10001);
	if (!new)
		return (free(str), NULL);
	new[advance + 10000] = '\0';
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	free(str);
	return (new);
}

void	read_file(t_data *data, int num)
{
	int		i;
	ssize_t	reader;

	i = 0;
	data->file = malloc(10001);
	if (!data->file)
		(free(data->fds), exit(1));
	data->file[10000] = '\0';
	while ((reader = read(data->fds[num], &data->file[i], 10000)))
	{
		i += reader;
		if (reader < 10000)
			break ;
		else
			data->file = ft_realloc(data->file, i);
		if (!data->file)
			(free(data->fds), exit(1));
	}
	if (reader == -1)
		data->error = 1;
	if (i != -1)
		data->file[i] = '\0';
}

void	read_stdin(t_data *data)
{
	int		i;
	ssize_t	reader;

	i = 0;
	data->file = malloc(10001);
	if (!data->file)
		exit(1);
	data->file[10000] = '\0';
	while ((reader = read(0, &data->file[i], 1)))
	{
		i += reader;
		if (i % 10000 == 0)
			data->file = ft_realloc(data->file, i);
		if (!data->file)
			exit(1);
	}
	if (reader == -1)
		data->error = 1;
	if (i != -1)
		data->file[i] = '\0';
}
