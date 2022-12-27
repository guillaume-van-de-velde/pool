/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 04:52:27 by svan-de-          #+#    #+#             */
/*   Updated: 2022/09/29 16:51:19 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	valeurstock;

	valeurstock = nb;
	i = 1;
	if (nb == 0 && power == 0)
		return (1);
	if (power == 0)
		return (1);
	if (power <= 0)
		return (0);
	while (i < power)
	{
		nb *= valeurstock;
		i++;
	}
	return (nb);
}
