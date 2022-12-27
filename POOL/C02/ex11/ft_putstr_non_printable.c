/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:50:16 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/26 04:18:13 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_set_hexarray(unsigned char *hexa)
{
	*hexa = '0';
	*(hexa + 1) = '1';
	*(hexa + 2) = '2';
	*(hexa + 3) = '3';
	*(hexa + 4) = '4';
	*(hexa + 5) = '5';
	*(hexa + 6) = '6';
	*(hexa + 7) = '7';
	*(hexa + 8) = '8';
	*(hexa + 9) = '9';
	*(hexa + 10) = 'a';
	*(hexa + 11) = 'b';
	*(hexa + 12) = 'c';
	*(hexa + 13) = 'd';
	*(hexa + 14) = 'e';
	*(hexa + 15) = 'f';
}

void	ft_display_hexa(unsigned char boxe)
{
	unsigned char	hexa_val[16];
	unsigned char	hexa_digit[2];
	unsigned char	i;
	unsigned char	save_boxe;

	ft_set_hexarray(hexa_val);
	save_boxe = boxe;
	write(1, "\\", 1);
	i = 0;
	while (boxe)
	{
		*(hexa_digit + i) = boxe % 16;
		boxe = boxe / 16;
		i++;
	}
	if (save_boxe < 16)
	{
		write(1, "0", 1);
		write(1, hexa_val + *hexa_digit, 1);
		return ;
	}
	write(1, (hexa_val + *(hexa_digit + 1)), 1);
	write(1, hexa_val + *hexa_digit, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	str_save;

	while (*str)
	{
		if (*str < 0)
		{
			str_save = ((unsigned char)(*str));
			if ((str_save < 32 || str_save >= 127) && str_save)
				ft_display_hexa(str_save);
			else if (str_save == 0)
				write (1, "\\00", 3);
			else
				write(1, str, 1);
		}
		else if (*str < 32 || *str >= 127)
			ft_display_hexa(*str);
		else
			write(1, str, 1);
		str++;
	}	
}
