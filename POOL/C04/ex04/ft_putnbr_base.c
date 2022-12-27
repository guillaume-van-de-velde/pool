/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:37:49 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/24 17:37:51 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_erreur(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[i] == '\0' || ft_strlen(base) == 1)
		return (0);
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && &base[i] != &base[j])
				return (0);
			j++;
		}
		if (base[i] == 127 || base[i] < 32 || base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int		lenbase;
	int		erreur;

	nb = nbr;
	lenbase = ft_strlen(base);
	erreur = ft_erreur(base);
	if (erreur == 1)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		if (nb < lenbase)
		{
			write(1, &base[nb], 1);
		}
		if (nb >= lenbase)
		{
			ft_putnbr_base(nb / lenbase, base);
			ft_putnbr_base(nb % lenbase, base);
		}
	}
}
