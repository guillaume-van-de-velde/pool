/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 04:53:15 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/24 04:58:59 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (nb == 0 && power == 0)
		return (1);
	if (power == 0)
		return (1);
	if (power <= 0)
		return (0);
	if (power > 0)
	{
		power--;
		nb *= ft_recursive_power(nb, power);
		return (nb);
	}
	return (nb);
}
