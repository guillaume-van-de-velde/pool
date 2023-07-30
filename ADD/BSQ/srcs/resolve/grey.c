#include "bsq.h"

void    fill_grey(char **map, t_coordinate stock, t_coordinate barrier, char barrier_char)
{
    int i;
    int j;

    i = stock.line;
    while (i <= barrier.line)
    {
        j = stock.column;
        while (j <= barrier.column)
        {
            if (map[i][j] != barrier_char)
                map[i][j] = '+';
            j++;
        }
        i++;
    }
}
