#include "rush01.h"

int row(int *soluce, int advance)
{
    int i;
    int j;
    int number;

    i = 0;
    while (i < 4)
    {
        j = i + 1;
        number = soluce[advance * 4 + i];
        while (j < 4 && number != 0)
        {
            if (number == soluce[advance * 4 + j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int col(int *soluce, int advance)
{
    int i;
    int j;
    int number;

    i = 0;
    while (i < 4)
    {
        j = i + 1;
        number = soluce[advance + (i * 4)];
        while (j < 4 && number != 0)
        {
            if (number == soluce[advance + (j * 4)])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int good_number(int *soluce, int advance, int i)
{
    int stock;

    stock = soluce[advance];
    soluce[advance] = i;
    if (!col(soluce, advance % 4) || !row(soluce, advance / 4))
        return (soluce[advance] = stock, 0);
    return (1);
}