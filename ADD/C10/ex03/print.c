#include "ft_hexdump.h"

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
    write(2, "hexdump: ", 9);
    write(2, arg, ft_strlen(arg));
    write(2, ": ", 2);
    write(2, str, ft_strlen(str));
    write(2, "\n", 1);
}

void    print_error_input()
{
    write(2, "hexdump: all input file arguments failed\n", 41);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
    if (nb > 15)
	{
		ft_putnbr(nb / 16);
		ft_putnbr(nb % 16);
	}
	else
    {
        if (nb < 10)
		    ft_putchar(nb + '0');
        else
            ft_putchar(nb + 'a' - 10);
    }
}