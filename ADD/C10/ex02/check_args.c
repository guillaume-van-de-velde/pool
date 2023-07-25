#include "ft_tail.h"

int ft_atoi(char *str)
{
    int i;
    int result;

    i = 0;
    result = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result);
}

int check_args(int argc, char **argv)
{
    if (argc < 2)
        return (0);
    if (argv[1][0] != '-' || argv[1][1] != 'c' || !ft_atoi(&argv[1][2]))
        return (0);
    return (1);
}
