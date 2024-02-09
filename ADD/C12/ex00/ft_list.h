/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:14:58 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 20:15:26 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

t_list	*ft_create_elem(void *data);

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

#endif