/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:13:33 by marvin            #+#    #+#             */
/*   Updated: 2022/12/19 22:13:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_nine(int *tab)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	while (tab[i] != -1)
	{
		if (tab[i] == 9)
			flag++;
		i++;
	}
	if (flag > 1)
		return (0);
	return (1);
}

void	ft_put_tab(int *tab, int n)
{
	int	i;

	i = 0;
	while (tab[i] != -1)
	{
		write(1, &"0123456789"[tab[i]], 1);
		i++;
	}
	i--;
	if (tab[i] == 9 && tab[0] == 10 - n)
		return ;
	write(1, ", ", 2);
}

int	ft_check(int n, int *tab, int last)
{
	int	i;

	i = tab[last] + 1;
	while (i < 10)
	{
		if (last < n - 1)
		{
			tab[last + 1] = i;
			ft_check(n, tab, last + 1);
		}
		if (ft_check_nine(tab))
			ft_put_tab(tab, n);
		tab[last] = i;
		i++;
	}
	return (0);
}

void	ft_print_combn(int n)
{
	int	tab[11];
	int	i;

	i = 0;
	if (n < 1 || n > 9)
		return ;
	while (i < 11)
		tab[i++] = -1;
	i = 0;
	while (i < n)
		tab[i++] = i - 1;
	ft_check(n, tab, 0);
	if (n == 1)
		write(1, "9", 1);
}
