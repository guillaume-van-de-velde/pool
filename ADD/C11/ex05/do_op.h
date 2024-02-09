/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:10:39 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 20:11:45 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>
# include <stdio.h>

int		ft_atoi(char *str);

int		plus(int a, int b);
int		minus(int a, int b);
int		divide(int a, int b);
int		time(int a, int b);
int		modulo(int a, int b);

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	result(int (*arr[5])(int, int), char op, int n1, int n2);
void	do_op(char *s1, char *op, char *s2);
int		main(int argc, char **argv);

#endif