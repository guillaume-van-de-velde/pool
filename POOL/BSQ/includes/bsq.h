/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 07:29:56 by vchakhno          #+#    #+#             */
/*   Updated: 2022/10/05 23:34:33 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>

# define EMPTY_CHAR 0
# define OBSTACLE_CHAR 1
# define SQUARE_CHAR 2

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	char	charset[3];
	char	**grey_zones;
}	t_map;

typedef struct s_maybe_map
{
	bool	exists;
	t_map	map;
}	t_maybe_map;

typedef struct s_maybe_obstacle
{
	bool	exists;
	int		x;
	int		y;
}	t_maybe_obstacle;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_square
{
	int	x;
	int	y;
	int	size;
}	t_square;

// map.c
t_maybe_map		create_map(int fileno);
void			display_map(t_map map);
void			free_map(t_map map);

// map_reader.c
int				positive_atoi(char *str, int *i);
bool			read_first_line(int fileno, t_map *map);
bool			check_map_char(char *line, t_map map);
bool			read_first_map_line(int fileno, t_map *map);
bool			read_other_map_lines(int fileno, t_map *map);

// square.c
t_square		ft_find_biggest_square(t_map map);
void			write_square(t_map map, t_square square);

// string.c
int				ft_strlen(char *str);
void			ft_putstr(char *str);
void			ft_putstr_err(char *str);
char			*ft_strdup(char *str);

// file_reader.c
typedef struct s_resizable_str {
	int		size;
	int		capacity;
	char	*str;
}	t_resizable_str;

void			ft_strcpy(char *dest, char *src);
t_resizable_str	get_line(int fileno);

// check_chars.c
bool			check_chars(char charset[3]);

#endif