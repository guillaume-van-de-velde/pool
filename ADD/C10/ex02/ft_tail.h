#ifndef FT_TAIL_H
#define FT_TAIL_H

#include <libgen.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void    for_stdin(int byte);

int     ft_strlen(char *str);
void    print_error(char *arg);
void    print_tail(char *tail);
void    print_head(char *argv);

int ft_atoi(char *str);
int check_args(int argc, char **argv);

void    gap(char *str, int byte);
int print_end(int byte, int fd);
int ft_tail(int byte, char **argv);
int main(int argc, char **argv);

#endif