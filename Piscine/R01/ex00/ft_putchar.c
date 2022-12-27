/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 04:52:57 by jode-bri          #+#    #+#             */
/*   Updated: 2022/12/21 22:57:26 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_affichage(char **comeback);
void	ft_putstr(char *str);
int		ft_verif(char *str);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
