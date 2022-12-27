/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:39:05 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/28 00:40:26 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putnbr_base(int nbr, char *base, char **str, int *i);
int		ft_erreur(char *base);
int		ft_strlen(char *str);
int		checkerror(char *str);
int		nb_base(char str, char *base);
int		whitespaces(char *str, int *ptr_i);
int		ft_atoi_base(char *str, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_strcpy(char *dest, char *src);

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

void	ft_putnbr_base(int nbr, char *base, char **str, int *i)
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
			(*str)[(*i)++] = '-';
			nb *= -1;
		}
		if (nb < lenbase)
		{
			(*str)[(*i)++] = base[nb];
		}
		if (nb >= lenbase)
		{
			ft_putnbr_base(nb / lenbase, base, str, i);
			ft_putnbr_base(nb % lenbase, base, str, i);
		}
	}
}
