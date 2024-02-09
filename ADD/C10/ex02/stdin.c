/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:56:44 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 19:57:07 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	for_stdin(int byte)
{
	char	*tail;
	int		i;
	ssize_t	reader;
	char	c;

	i = 0;
	reader = 1;
	tail = malloc(byte + 1);
	if (!tail)
		return ;
	while (i < byte && reader > 0)
	{
		reader = read(0, &tail[i], 1);
		if (reader < 0)
			return (free(tail));
		i++;
	}
	if (reader == 0)
		tail[i - 1] = '\0';
	while (reader > 0)
	{
		reader = read(0, &c, 1);
		if (reader < 0)
			return (free(tail));
		if (reader)
		{
			tail[byte] = c;
			gap(tail, byte);
		}
		i++;
	}
	tail[byte] = '\0';
	print_tail(tail);
	free(tail);
}
