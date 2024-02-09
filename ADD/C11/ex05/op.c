/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:12:24 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 20:12:38 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	plus(int a, int b)
{
	return (a + b);
}

int	minus(int a, int b)
{
	return (a - b);
}

int	divide(int a, int b)
{
	return (a / b);
}

int	time(int a, int b)
{
	return (a * b);
}

int	modulo(int a, int b)
{
	return (a % b);
}
