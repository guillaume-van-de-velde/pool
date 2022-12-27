/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:57:33 by svan-de-          #+#    #+#             */
/*   Updated: 2022/10/06 19:55:00 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*mytab;

	mytab = malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		mytab[i] = f(tab[i]);
		i++;
	}
	return (mytab);
}
