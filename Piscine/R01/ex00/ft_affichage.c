/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:53:25 by svan-de-          #+#    #+#             */
/*   Updated: 2022/12/21 22:57:28 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_verif(char *str);

void	ft_affichage(char **comeback)
{
	int	i;

	i = 0;
	while (comeback[i] != NULL)
	{
		ft_putstr(comeback[i]);
		ft_putchar('\n');
		i++;
	}
}
