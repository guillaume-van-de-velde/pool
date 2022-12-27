/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:32:28 by vchakhno          #+#    #+#             */
/*   Updated: 2022/10/05 23:37:57 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

bool	check_chars(char charset[3])
{
	if (charset[0] == charset[1])
	{
		ft_putstr_err("map error\n");
		return (false);
	}
	if (charset[0] == charset[2])
	{
		ft_putstr_err("map error\n");
		return (false);
	}
	if (charset[1] == charset[2])
	{
		ft_putstr_err("map error\n");
		return (false);
	}
	return (true);
}
