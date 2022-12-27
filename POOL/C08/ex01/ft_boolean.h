/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 04:45:19 by svan-de-          #+#    #+#             */
/*   Updated: 2022/10/02 04:46:13 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

# define EVEN(x) ((x) % 2 == 0)
# define SUCCESS 0
# define ODD_MSG "I have an odd number of arguments.\n"
# define EVEN_MSG "I have an even number of arguments.\n"

#endif
