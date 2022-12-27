/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:14:47 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/27 00:14:48 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	stock;
	int	i;

	i = 0;
	stock = max - min;
	tab = *range;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = malloc(sizeof(int) * stock);
	if (!tab)
		return (-1);
	while (i < stock)
	{
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (stock);
}
