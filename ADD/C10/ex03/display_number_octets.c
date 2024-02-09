/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_number_octets.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:57:32 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 19:57:44 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_count_hex(int nb, int *len)
{
	if (nb > 15)
	{
		ft_count_hex(nb / 16, len);
		ft_count_hex(nb % 16, len);
	}
	else
		(*len)++;
}

void	display_number_octets(int octets, int option)
{
	int	len;

	len = 0;
	ft_count_hex(octets, &len);
	if (!option)
		len = 7 - len;
	else
		len = 8 - len;
	while (len > 0)
	{
		write(1, "0", 1);
		len--;
	}
	ft_putnbr(octets);
}
