/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:28:58 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 20:29:28 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;

	if (!begin_list)
		return (0);
	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (begin_list)
	{
		if (i == nbr)
			return (begin_list);
		i++;
		begin_list = begin_list->next;
	}
	return (NULL);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*list;
	void	*tmp;
	int		size;
	int		i;

	size = ft_list_size(begin_list);
	if (size == 0 || size == 1)
		return ;
	i = 0;
	while (i < size / 2 + 1)
	{
		list = ft_list_at(begin_list, size - i - 1);
		tmp = list->data;
		list->data = begin_list->data;
		begin_list->data = tmp;
		begin_list = begin_list->next;
		size--;
		i++;
	}
}
