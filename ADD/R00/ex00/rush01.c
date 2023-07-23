/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:16:27 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/17 17:34:54 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_cas(int x, int y, int i, int j)
{
	if (i == 0)
	{
		if (j == 0)
			ft_putchar('/');
		else if (j == x - 1)
			ft_putchar(92);
		else
			ft_putchar('*');
	}
	else if ((i == y - 1) && y != 1)
	{
		if (j == 0)
			ft_putchar(92);
		else if (j == x - 1)
			ft_putchar('/');
		else
			ft_putchar('*');
	}
	else
	{
		if (j == 0 || j == x - 1)
			ft_putchar('*');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (x <= 0 || y <= 0)
		return ;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_cas(x, y, i, j);
			j++;
		}
		i++;
		ft_putchar(10);
	}
}
