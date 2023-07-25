#include "ft_tail.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    print_error(char *arg)
{
    char *str;

    str = strerror(errno);
    write(2, "tail: cannot open '", 19);
    write(2, arg, ft_strlen(arg));
    write(2, "' for reading: ", 15);
    write(2, str, ft_strlen(str));
    write(2, "\n", 1);
}

void    print_tail(char *tail)
{
    int i;

    i = 0;
    while (tail[i])
        i++;
    write(1, tail, i);
}

void    print_head(char *argv)
{
    write(1, "==> ", 4);
    write(1, argv, ft_strlen(argv));
    write(1, " <==\n", 5);
}