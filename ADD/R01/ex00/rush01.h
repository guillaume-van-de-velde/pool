/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:51:08 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/13 16:36:22 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_index
{
	int	i;
	int	j;
	int	k;
	int	index_dr;
}	t_index;

int		*get_board(char *str);

int		row(int *soluce, int advance);
int		col(int *soluce, int advance);
int		good_number(int *soluce, int advance, int i);

int		soluce_found(void);
int		error(void);
void	print_soluce(int *soluce, int number);
int		main(int argc, char **argv);

int		ft_strlen(char *str);
int		parsing(char *str);

int		check(int *view, int ask);
int		good_view(int *board, int *soluce);

void	back_tracking(int *board, int *soluce, int advance);
void	set_soluce(int *soluce);
void	start_soluce(int *board);

#endif