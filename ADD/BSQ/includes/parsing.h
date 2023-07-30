#ifndef PARSING_H
#define PARSING_H

#include "bsq.h"

int ft_atoi_bsq(char *str);
void    fill_chars(t_chars *chars, char *str);

int check_length_and_chars(char **map, t_chars chars);
void    check_file(t_data *data);

int ft_compteurdemot(char *s, char c);
void	*ft_free(char **split, int j);
char	*ft_dup2(char *s, char c);
char	**ft_if(char **split, char *s, char c, size_t *iandj);
char	**ft_split(char *s, char c);

char    *ft_realloc(char *str, int advance);
void    read_file(t_data *data, int num);
void    read_stdin(t_data *data);

void    check_args(int argc, char **argv, t_data *data);

void    parsing(t_data *data, int num);

#endif