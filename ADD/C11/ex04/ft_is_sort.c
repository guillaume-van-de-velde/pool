/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:09:54 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 20:10:06 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	rise;
	int	decrease;

	i = 0;
	rise = 0;
	decrease = 0;
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			rise++;
		if (f(tab[i], tab[i + 1]) <= 0)
			decrease++;
		i++;
	}
	if (rise == i || decrease == i)
	{
		return (1);
	}
	return (0);
}
