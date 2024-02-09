/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:57:03 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 20:58:52 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>

typedef struct s_data
{
	char	**dict;
	char	*number;
	int		error;
	int		writted;
	int		no_print;
}	t_data;

void	hundreds(t_data *data, int index);
void	tens(t_data *data, int index);
void	units(t_data *data, int index, int len);
void	greatness(t_data *data, int len);

void	recursive_resolve(t_data *data, int len, int i);
void	resolve(t_data *data);

int		ft_isset(char c, char *set);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strdup(char *src);

int		ft_len(long nb);
char	*ft_itoa(int n);

void	free_split(char **split);
int		bigarray_len(char **bigarray);
int		ft_strlen(char *str);

int		ft_compteurdemot(char *s, char c);
void	*ft_free(char **split, int j);
char	*ft_dup2(char *s, char c);
char	**ft_if(char **split, char *s, char c, size_t *iandj);
char	**ft_split(char *s, char c);

int		print_error(void);
int		print_dict_error(void);

char	*fill_dict_create_hundred(int index);
char	*fill_dict_create_twenty(int index);
char	*fill_dict_create_ten(int index);
char	*fill_dict_create(int index);
void	create_dict(t_data *data);

void	keep_only_translate(t_data *data);
void	free_other_data(char **dict, int len);
void	swap_string(char **dict, int i, int j);
int		good_number_for_place(char *s1, char *s2);
char	*thousand_plus(int place);
char	*value_ref(int place);
int		search_swapper(char **dict, int i);
int		good_place(char *str, int i, int *error);
int		good_line(char *str);
void	check_dict_lines(t_data *data);

char	*ft_realloc(char *str, int actual);
char	*get_file(int fd);
char	**get_dict(char *str);
void	parse_dict(t_data *data, char *file);

int		valide_number(char *str);
void	check_args(int argc, char **argv, t_data *data);

void	set_data(t_data *data);
void	parsing(int argc, char **argv, t_data *data);

int		main(int argc, char **argv);

#endif