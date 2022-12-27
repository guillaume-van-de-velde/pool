/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 05:47:01 by svan-de-          #+#    #+#             */
/*   Updated: 2022/10/03 05:47:45 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;
	int		len;

	len = ft_strlen(src);
	i = 0;
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*a;
	int			i;

	i = 0;
	a = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!a)
		return (NULL);
	while (i < ac)
	{
		a[i].str = av[i];
		a[i].copy = ft_strdup(a[i].str);
		if (!a[i].copy)
			return (NULL);
		a[i].size = ft_strlen(a[i].str);
		i++;
	}
	a[i].size = 1;
	a[i].str = '\0';
	a[i].copy = '\0';
	return (a);
}
/*
int main(int ac, char **av)
{
	t_stock_str	*s;
	s = ft_strs_to_tab(ac, av);
	int	i;
	i = 0;
	printf("La taille de la struct est : %ld\n", sizeof(t_stock_str));
	while (s[i].str != NULL)
	{
		printf("la reponse est %d\n", s[i].size);
		printf("la reponse est %s\n", s[i].str);
		printf("la reponse est %s\n\n", s[i].copy);
		i++;
	}
}*/
