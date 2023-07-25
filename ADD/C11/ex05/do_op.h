#ifndef DO_OP_H
#define DO_OP_H

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str);

int plus(int a, int b);
int minus(int a, int b);
int divide(int a, int b);
int time(int a, int b);
int modulo(int a, int b);

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void    result(int (*arr[5])(int, int), char op, int n1, int n2);
void    do_op(char *s1, char *op, char *s2);
int main(int argc, char **argv);

#endif