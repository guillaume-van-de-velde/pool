/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 05:21:18 by jode-bri          #+#    #+#             */
/*   Updated: 2022/12/21 22:56:37 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdlib.h>
#include <stdio.h>

void    ft_putchar(char c);

void    ft_putstr(char *str);

char    **ft_split(char *str);

void	ft_erreur();

void	ft_comeback(char **comeback);

void    ft_affichage(char **comeback);

int     ft_verifarg(char *str);

int	main(int argc, char **argv)
{
	if (ft_verifarg(argv[1]) == 1 || argc != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	char	tab[16];
	char	**comeback;
	int	i;
	int	j;
	int	k;
	int x;

	x = 0;
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] >= '1' && argv[1][i] <= '4')
		{
			tab[x] = argv[1][i];
			x++;
		}
		i++;
	}
	comeback = malloc(sizeof(char *) * 4 + 1);
	j = 0;
	while (j < 4)
	{
		comeback[j] = malloc(sizeof(char) * 4 + 1);
		j++;
	}
	j = 0;
	i = 0;
	k = 0;
	while (j < 4)
	{
		k = 0;
		while (k < 4)
		{
			comeback[j][k] = tab[i];
			k++;
			i++;
		}
		comeback[j][k] = '\0';
		j++;
	}

	comeback[4] = NULL;
	 comeback[j] = '\0';
	ft_affichage(comeback);
} */

		/*char	**super_tableau;
		char	*haut;
		char	*bas;
		char	*gauche;
		char	*droite;
		char	tab[31];
		int	i;
		int	j;
		int	k;

		k = 0;
		i = 0;
		j = 0;
		super_tableau = malloc(sizeof(super_tableau) * 4 + 1);
		super_tableau[5] = 0;
		while (super_tableau[i])
			super_tableau[i] = malloc(sizeof(char * 4 + 1);
		while (argv[1][i])
		{
			if (argv[1][i] >= '1' && argv[1][i] <= '4')
				tab[i] = argv[1][i];
			i++;
		}
		tab[i] = '\0';
		ft_suite(tab, );
		while (j < 4)
			haut[k++] = tab[j++];
		k = 0;
		while (j < 8)
			bas[k++] = tab[j++];
		k = 0;
		while (j < 12)
			gauche[k++] = tab[j++];
		k = 0;
		while (j < 16)
			droite[k++] = tab[j++];
		haut[4] = '\0';
		bas[4] = '\0';
		gauche[4] = '\0';
		droite[4] = '\0';
		ft_putstr(haut);
		ft_putchar('\n');
		ft_putstr(bas);
		ft_putchar('\n');
		ft_putstr(gauche);
		ft_putchar('\n');
		ft_putstr(droite);
		ft_putchar('\n');
	}

}
*/
