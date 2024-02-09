/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:00:48 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 20:01:21 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	display_octets_char(char *str)
{
	int	i;

	i = 0;
	ft_putchar('|');
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || !(str[i] >= 32 && str[i] <= 126))
			ft_putchar('.');
		else
			ft_putchar(str[i]);
		i++;
	}
	ft_putchar('|');
	ft_putchar('\n');
}

void	display_octets_hex_option(char *str)
{
	int	i;
	int	at_print;
	int	len;

	at_print = 52;
	i = 0;
	ft_putchar(' ');
	at_print--;
	while (str[i])
	{
		len = 0;
		ft_putchar(' ');
		if (i == 8)
			(ft_putchar(' '), at_print--);
		ft_count_hex(str[i], &len);
		if (len < 2)
			ft_putchar('0');
		ft_putnbr(str[i]);
		i++;
		at_print -= 3;
	}
	while (at_print > 0)
		(ft_putchar(' '), at_print--);
}

void	display_octets_hex(char *str)
{
	int	i;
	int	len;
	int	at_print;

	i = 0;
	at_print = 40;
	while (str[i] && str[i + 1])
	{
		len = 0;
		ft_putchar(' ');
		ft_count_hex(str[i + 1], &len);
		if (len < 2)
			ft_putchar('0');
		ft_putnbr(str[i + 1]);
		len = 0;
		ft_count_hex(str[i], &len);
		if (len < 2)
			ft_putchar('0');
		ft_putnbr(str[i]);
		i += 2;
		at_print -= 5;
	}
	while (at_print > 0)
		(ft_putchar(' '), at_print--);
	ft_putchar('\n');
}

void	result_management(t_data *data)
{
	static char	cmp[17] = {0};
	static int	flag = 0;

	if (!data->str[0])
		return ;
	if (!ft_strncmp(cmp, data->str, ft_strlen(data->str)) && ft_strlen(data->str) == ft_strlen(cmp))
	{
		if (flag != 1)
			(ft_putchar('*'), ft_putchar('\n'), flag = 1);
		return ;
	}
	flag = 0;
	ft_strcpy(cmp, data->str);
	display_number_octets(data->octets, data->option);
	if (!data->option)
		display_octets_hex(data->str);
	else
	{
		display_octets_hex_option(data->str);
		display_octets_char(data->str);
	}
}
