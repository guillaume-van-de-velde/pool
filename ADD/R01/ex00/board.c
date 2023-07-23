#include "rush01.h"

int *get_board(char *str)
{
    int *board;
    int i;
    int j;

    i = 0;
    j = 0;
    board = malloc(sizeof(int) * 16);
    if (!board)
        return (NULL);
    while (str[i])
    {
        if (str[i] != ' ')
        {
            board[j] = str[i] - '0';
            j++;
        }
        i++;
    }
    return (board);
}