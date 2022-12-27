/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 02:37:03 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/15 12:11:16 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	reverse(int *a, int *b)
{
	int	stock;

	stock = *a;
	*a = *b;
	*b = stock;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < (size / 2))
	{
		reverse(&tab[i], &tab[(size - 1) - i]);
		i++;
	}
}
