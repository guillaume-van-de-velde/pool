/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:16:51 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/19 16:44:55 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_wh(unsigned int *i, unsigned int *k, char *dest, char *src)
{
	dest[*i] = src[*k];
	*k = *k + 1;
	*i = *i + 1;
}

void	ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	if (j >= nb)
	{
		while (k < nb)
			ft_wh(&i, &k, dest, src);
	}
	if (j < nb)
	{
		while (k < j)
			ft_wh(&i, &k, dest, src);
	}
	dest[i] = '\0';
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	res;
	int				j;

	i = 0;
	res = 0;
	while (dest[i] != '\0')
		i++;
	while (src[res] != '\0')
		res++;
	if (size <= i)
	{
		res = res + size;
		j = 0;
	}
	if (size > i)
	{
		res = res + i;
		j = size - i - 1;
	}
	ft_strncat(dest, src, j);
	return (res);
}
