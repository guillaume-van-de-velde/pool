#ifndef FT_HEXDUMP_H
#define FT_HEXDUMP_H

#include <libgen.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct  s_data
{
    int     option;
    char    *str;
    char    **files;
    int     fd;
    int     stdin;
    int     octets;
    int     link;
    int     input;
}   t_data;

void    for_stdin(t_data *data);

char	*ft_strcpy(char *dest, char *src);
int	ft_strncmp(char *s1, char *s2, unsigned int n);

int ft_strlen(char *str);
void    print_error(char *arg);
void    print_error_input();
void	ft_putchar(char c);
void	ft_putnbr(int nb);

void	ft_count_hex(int nb, int *len);
void    display_number_octets(int octets, int option);

void    display_octets_char(char *str);
void    display_octets_hex_option(char *str);
void    display_octets_hex(char *str);
void    result_management(t_data *data);

void    fill_data(t_data *data, int argc, char **argv);
void    set_data(t_data *data);

int file_hexdump(t_data *data, int i);
void    ft_hexdump(t_data *data);
int main(int argc, char **argv);

#endif