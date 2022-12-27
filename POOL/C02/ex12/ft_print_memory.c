/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 07:18:49 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/25 07:18:51 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hex(unsigned char c)
{
	ft_putchar("0123456789abcdef"[c / 16]);
	ft_putchar("0123456789abcdef"[c % 16]);
}

void	ft_print_data(char *s, unsigned int size)
{
	unsigned int	i;

	i = -1;
	while (++i < size)
	{
		if (!(i % 2))
			ft_putchar(' ');
		ft_hex(s[i]);
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (!(i % 2))
			write(1, " ", 1);
		i++;
	}
	ft_putchar(' ');
	i = -1;
	while (++i < size)
	{
		if (s[i] < ' ' || s[i] == 127)
			ft_putchar('.');
		else
			ft_putchar(s[i]);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				j;

	i = 0;
	while (i < size)
	{
		j = 56;
		while (j >= 0)
		{
			ft_hex((unsigned long int)(addr + i) >> j & 0xff);
			j -= 8;
		}
		ft_putchar(':');
		if (size - i < 16)
			ft_print_data(addr + i, size - i);
		else
			ft_print_data(addr + i, 16);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
