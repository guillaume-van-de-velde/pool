/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 02:33:08 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/28 02:33:20 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	ft_ischarset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		else
			i++;
	}
	return (0);
}

int	ft_compteurdemot(char *str, char *charset)
{
	int	compteurdemot;
	int	i;

	while (str[i])
	{
		if (!ft_ischarset(str[i], charset))
		{
			compteurdemot++;
			while (!ft_ischarset(str[i], charset) && str[i])
				i++;
		}
		else
			i++;
	}
	return (compteurdemot);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str, char *charset)
{
	int		len;
	int		i;
	char	*dup;

	i = 0;
	len = ft_strlen(str);
	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	while (str[i] && !ft_ischarset(str[i], charset))
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		j;
	int		compteurdemot;

	i = 0;
	j = 0;
	compteurdemot = ft_compteurdemot(str, charset);
	split = malloc(sizeof(char *) * compteurdemot + 1);
	if (!split)
		return (NULL);
	while (str[i])
	{
		if (!ft_ischarset(str[i], charset))
		{
			split[j] = ft_strdup(&str[i], charset);
			j++;
			while (!ft_ischarset(str[i], charset) && str[i])
				i++;
		}
		else
			i++;
	}
	split[j] = '\0';
	return (split);
}
