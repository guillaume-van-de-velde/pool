/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:06:33 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/10 17:08:39 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "bsq.h"

typedef struct s_chars
{
	int		line;
	char	nul;
	char	barrier;
	char	full;
}	t_chars;

typedef struct s_data
{
	t_chars	chars;
	int		*fds;
	char	*file;
	char	**map;
	int		error;
}	t_data;

typedef struct s_coordinate
{
	int	line;
	int	column;
}	t_coordinate;

typedef struct s_square
{
	t_coordinate	spot;
	int				size;
}	t_square;

#endif