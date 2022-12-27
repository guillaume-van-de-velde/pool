/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 02:29:07 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/27 01:32:25 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_strswap(char **s1, char **s2)
{
	char	*c;

	c = *s1;
	*s1 = *s2;
	*s2 = c;
}

int	main(int ac, char **av)
{
	int	j;

	j = 1;
	while (j < ac - 1)
	{
		if (ft_strcmp(av[j], av[j + 1]) > 0)
		{
			ft_strswap(&av[j], &av[j + 1]);
			j = 1;
		}
		else
			j++;
	}
	j = 1;
	while (j < ac)
	{
		ft_putstr(av[j]);
		ft_putchar('\n');
		j++;
	}
	return (0);
}
