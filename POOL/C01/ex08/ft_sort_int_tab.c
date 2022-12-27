/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:14:28 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/15 14:45:06 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *k)
{
	int	mem;

	mem = *a;
	*a = *k;
	*k = mem;
}

void	compare(int *tab, int size, int a)
{
	int	k;

	k = a + 1;
	while (k < size)
	{
		if (tab[a] > tab[k])
		{
			swap(&tab[a], &tab[k]);
		}
		k++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	a;

	a = 0;
	while (a < size)
	{
		compare(tab, size, a);
		a++;
	}
}
