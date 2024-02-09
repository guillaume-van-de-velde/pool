/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:50:15 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 20:50:40 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	soluce_found(void)
{
	static int  soluce = 0;

	soluce++;
	return (soluce);
}

int	error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void	print_soluce(int *soluce, int number)
{
	int		i;
	char	c;

	i = 0;
	if (number != 1)
		return ;
	while (i < 16)
	{
		c = soluce[i] + '0';
		write(1, &c, 1);
		if ((i + 1) % 4 == 0)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	int		*board;

	if (argc != 2)
		return (error());
	str = argv[1];
	if (!parsing(str))
		return (error());
	board = get_board(str);
	if (!board)
		return (error());
	start_soluce(board);
	if (soluce_found() == 1)
		return (error());
}
