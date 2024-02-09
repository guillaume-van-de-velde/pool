/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:10:11 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 20:10:35 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

void	result(int (*arr[5])(int, int), char op, int n1, int n2)
{
	char	*symbols;
	int		i;

	symbols = "+-/*%";
	i = 0;
	while (symbols[i])
	{
		if (op == symbols[i])
			ft_putnbr(arr[i](n1, n2));
		i++;
	}
}

void	do_op(char *s1, char *op, char *s2)
{
	int	(*arr[5])(int, int);
	int	n1;
	int	n2;

	arr[0] = plus;
	arr[1] = minus;
	arr[2] = divide;
	arr[3] = time;
	arr[4] = modulo;
	n1 = ft_atoi(s1);
	n2 = ft_atoi(s2);
	if (*op != '+' && *op != '-' && *op != '/' && *op != '*' && *op != '%')
		return ((void)write(1, "0\n", 2));
	if (n2 == 0)
	{
		if (*op == '/')
			return ((void)write(1, "Stop : division by zero\n", 24));
		if (*op == '%')
			return ((void)write(1, "Stop : modulo by zero\n", 22));
	}
	result(arr, *op, n1, n2);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		do_op(argv[1], argv[2], argv[3]);
}