/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:02:23 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/17 23:43:22 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_wh(unsigned int *i, unsigned int *k, char *dest, char *src)
{
	dest[*i] = src[*k];
	*k = *k + 1;
	*i = *i + 1;
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
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
	return (dest);
}
