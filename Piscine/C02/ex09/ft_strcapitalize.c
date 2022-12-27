/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:41:17 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/25 21:44:19 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] += 32;
		}
	i++;
	}
	return (str);
}

int	ft_alphanum(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;

	i = 1;
	ft_strlowcase(str);
	if ((str[0] >= 97 && str[0] <= 122) && str[0] != '\0')
		str[0] -= 32;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			if (ft_alphanum(str[i - 1]) == 1)
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
