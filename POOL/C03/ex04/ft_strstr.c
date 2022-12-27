/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 05:03:33 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/19 05:15:09 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				vc;

	i = 0;
	vc = 0;
	while (s2[i] != '\0' && vc == 0 && i < n)
	{
		vc = s1[i] - s2[i];
		i++;
	}
	if (vc < 0)
		return (-1);
	if (vc > 0)
		return (1);
	if (i < n)
		return (-1);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int				i;
	unsigned int	size_find;
	int				stock;

	size_find = 0;
	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (to_find[size_find] != '\0')
		size_find ++;
	while (str[i] != '\0')
	{
		if (to_find[0] == str[i])
		{
			stock = ft_strncmp(&to_find[0], &str[i], size_find);
			if (stock == 0)
				return (str + i);
		}
		else if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return (NULL);
}
