/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:33:16 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/28 04:30:17 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

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
