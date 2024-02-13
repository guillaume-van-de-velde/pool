/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:56:44 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/13 16:57:00 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	read_on_stdin(int byte, ssize_t reader, char *tail, char *c)
{
	int		i;

	i = 0;
	while (i < byte && reader > 0)
	{
		reader = read(0, &tail[i], 1);
		if (reader < 0)
			return (0);
		i++;
	}
	if (reader == 0)
		tail[i - 1] = '\0';
	while (reader > 0)
	{
		reader = read(0, c, 1);
		if (reader < 0)
			return (0);
		if (reader)
		{
			tail[byte] = *c;
			gap(tail, byte);
		}
		i++;
	}
	return (1);
}

void	for_stdin(int byte)
{
	char	*tail;
	ssize_t	reader;
	char	c;

	reader = 1;
	tail = malloc(byte + 1);
	if (!tail)
		return ;
	if (!read_on_stdin(byte, reader, tail, &c))
		return (free(tail));
	tail[byte] = '\0';
	print_tail(tail);
	free(tail);
}
