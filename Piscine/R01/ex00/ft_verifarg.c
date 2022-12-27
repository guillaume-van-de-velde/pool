/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:54:09 by svan-de-          #+#    #+#             */
/*   Updated: 2022/12/21 22:57:35 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_affichage(char **comeback);
void	ft_putchar(char c);
void	ft_putstr(char *str);

int	ft_verifarg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '1' && str[i] <= '4') || str[i] == ' '))
			return (1);
		i++;
	}
	if (i != 31)
		return (1);
	return (0);
}
