/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:38:54 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/28 18:46:27 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void	ft_putnbr_base(int nbr, char *base, char **str, int *i);
int		ft_erreur(char *base);
int		ft_strlen(char *str);
int		checkerror(char *str);
int		nb_base(char str, char *base);
int		whitespaces(char *str, int *ptr_i);
int		ft_atoi_base(char *str, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_strcpy(char *dest, char *src);

int	checkerror(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] <= 32 || str[i] == 127 || str[i] == 43 || str[i] == 45)
			return (0);
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	nb_base(char str, char *base)
{
	int	nb;

	nb = 0;
	while (base[nb] != '\0')
	{
		if (str == base[nb])
			return (nb);
		nb++;
	}
	return (-1);
}

int	whitespaces(char *str, int *ptr_i)
{
	int	count;
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	count = 1;
	while (str[i] && (str[i] == 43 || str[i] == 45))
	{
		if (str[i] == 45)
			count *= -1;
		i++;
	}
	*ptr_i = i;
	return (count);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	negative;
	int	nb;
	int	nb2;
	int	begin_len;

	nb = 0;
	i = 0;
	begin_len = checkerror(base);
	if (begin_len >= 2)
	{
		negative = whitespaces(str, &i);
		nb2 = nb_base(str[i], base);
		while (nb2 != -1)
		{
			nb = (nb * begin_len) + nb2;
			i++;
			nb2 = nb_base(str[i], base);
		}
		return (nb *= negative);
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb0;
	char	*str;
	int		i;

	if (ft_strlen(base_from) <= 1 || ft_strlen(base_to) <= 1)
		return (NULL);
	i = 0;
	nb0 = ft_atoi_base(nbr, base_from);
	str = malloc(sizeof(char) * 20000);
	if (!str)
		return (NULL);
	ft_putnbr_base(nb0, base_to, &str, &i);
	str[i] = '\0';
	return (str);
}
