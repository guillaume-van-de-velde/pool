#include "bsq.h"

void    fill_square(t_square *square)
{
    square->line = 0;
    square->column = 0;
    square->size = 0;
}

void    print_map(char **map, t_square biggest, t_chars chars)
{
    int line;
    int column;

    line = 0;
    while (map[line])
    {
        column = 0;
        while (map[line][column])
        {
            if ((line >= biggest.line && line < biggest.line + size) && (column >= biggest.column && column < biggest.column + size))
                write(1, chars.full, 1);
            else if (map[line][column] == 'g')
                write(1, chars.nul, 1);
            else
                write(1, map[line][column], 1);
            column++;
        }
        line++;
    }
}

void    fill_grey(char **map, int line, int column, int size_c, char barrier)
{
    int i;
    int j;

    j = 0;
    while (j < size_c)
    {
        i = 0;
        while (i < size_c - 1 && map[line + j][column + i] != barrier)
            map[line + j][column + i] = 'g';
        j++;
    }
}

void    delete_grey(char **map, t_coordinate coordinate, int size, char nul)
{
    int stock;

    coordinate.column++;
    stock = coordinate.column;
    while (size > 0)
    {
        coordinate.column = stock;
        while (map[coordinate.line][coordinate.column] == 'g')
            map[coordinate.line][coordinate.column++] = nul;
        size--;
    }
}

int check_line_and_column(char **map, int line, int column, t_chars chars, int stock_line, int stock_line, int size)
{
    t_coordinate    first_barrier_column;
    int stock_index;
    int found_barrier;
    int first_barrier_column;

    stock_index = column;
    found_barrier = 0;
    first_barrier_column.line = line;
    first_barrier_column.columns = 0;
    while (column > stock_column)
    {
        if (map[line][column] == chars.barrier)
        {
            if (first_barrier_column == 0)
            {
                found_barrier = 2;
                first_barrier_colomn = column;
            }
        }
        else
            map[line][column] = 'g';
        column--;
    }
    while (line > stock_line)
    {
        if (map[line][stock_index] == chars.barrier)
            found_barrier = 1;
        else
            map[line][stock_index] = 'g';
        line--;
    }
    if (found_barrier)
    {
        if (found_barrier == 2)
            delete_grey(map, first_barrier_column, size, chars.nul);
        return (0);
    }
    return (1);
}

int    enlargment(char **map, int line, int column, t_chars chars, int size)
{
    int stock_column;
    int stock_line;

    stock_column = column - size;
    stock_line = line - size;
    while (map[line])
    {
        if (map[line][column])
            if (!check_line_and_column(map, line, column, chars, stock_line, stock_column, size))
                break ;
        size++;
        column++;
        line++;
    }
    return (size);
}

t_square    calcul_square(t_data *data, char **map, int line, int column, t_square biggest)
{
    int         new_size;
    int         size_c;
    int         size_l;
    int         bad_square;
    int         actual_barrier;

    size_l = 0;
    bad_square = 0;
    actual_barrier = 0;
    if (biggest.square)
    {
        while (size_l < biggest.size)
        {
            size_c = actual_barrier;
            while (size_c < biggest.size)
            {
                if (map[line + size_l][column + size_c] == data->chars.barrier && actual_barrier < size_c)
                {
                    bad_square = 1;
                    actual_barrier += size_c;
                    fill_grey(map, line, column, size_c, data->chars.barrier);
                }
                size_c++;
            }
            size_l++;
        }
    }
    if (bad_square == 0)
    {
        new_size = enlargment(map, line + size, column + size, data->chars, biggest.size);
        return ((t_square){line, column, new_size});
    }
    return ((t_square){0, 0, 0});
}

void    resolve(t_data *data)
{
    int line;
    int column;
    char    **map;
    t_square   biggest;
    t_square    actual;

    fill_square(&biggest);
    map = data->&map[1];
    line = 0;
    while (map[line])
    {
        column = 0;
        while (map[line][column])
        {
            if (map[line][column] == data->chars->nul)
            {
                actual = calcul_square(data, map, line, column, biggest);
                if (actual.size == biggest.size)
                    biggest = actual;
            }
            column++;
        }
        line++;
    }
    print_map(map, biggest, data->chars);
}