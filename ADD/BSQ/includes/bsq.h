#ifndef BSQ_H
#define BSQ_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>

typedef struct s_chars
{
    int     line;
    char    nul;
    char    barrier;
    char    full;
}   t_chars;

typedef struct s_data
{
    t_chars chars;
    int     *fds;
    char    *file;
    char    **map;
    int     error;
}   t_data;

typedef struct s_coordinate
{
    int line;
    int column;
}   t_coordinate;

typedef struct s_square
{
    t_coordinate spot;
    int size;
}   t_square;

#include "parsing.h"
#include "resolve.h"

int ft_strlen(char *str);

void    print_error();

void	free_split(char **split);
void    free_map(t_data *data);
void    free_all(t_data *data);

void    set_chars(t_chars *chars);
void    set_data(t_data *data);

void    bsq_for_file(t_data *data);
int main(int argc, char **argv);

#endif