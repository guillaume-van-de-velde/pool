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

typedef struct s_square
{
    int line;
    int column;
    int size;
}   t_square;

typedef struct s_coordinate
{
    int line;
    int column;
}   t_coordinate;

#include "parsing.h"
#include "resolve.h"

#endif