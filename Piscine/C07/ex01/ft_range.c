/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:51:34 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/28 01:07:07 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;
	int	stock;

	i = 0;
	stock = max - min;
	if (min >= max)
		return (NULL);
	tab = malloc(sizeof(int) * stock);
	if (!tab)
		return (NULL);
	while (i < stock)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
