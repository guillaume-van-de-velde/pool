#include "bsq.h"

int ft_atoi_bsq(char *str)
{
    int result;
    int i;

    i = 0;
    result = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if (i == 0 || i != ft_strlen(str) - 3)
        return (0);
    return (result);
}

void    fill_chars(t_chars *chars, char *str)
{
    int     len;

    len = ft_strlen(str);
    if (len < 4)
        return ;
    chars->full = str[len - 1];
    chars->barrier = str[len - 2];
    chars->nul = str[len - 3];
    chars->line = ft_atoi_bsq(str);
    if (chars->line == 0)
        set_chars(chars);
}