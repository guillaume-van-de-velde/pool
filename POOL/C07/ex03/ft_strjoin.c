/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:36:17 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/29 01:55:58 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_lngh(char **strs, int size, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		i++;
	}
	len = len + (size - 1) * ft_strlen(sep) + 1;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;

	if (size == 0)
	{
		str = malloc(sizeof(char));
		*str = 0;
		return (str);
	}
	str = malloc(sizeof(char) * ft_lngh(strs, size, sep));
	if (!str)
		return (NULL);
	*str = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < size - 1)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}
