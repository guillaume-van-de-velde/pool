/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:26:51 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/10 17:50:59 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	free_list(t_list *list, void (*free_fct)(void *))
{
	t_list	*tmp;

	tmp = list;
	list = list->next;
	(*free_fct)(tmp->data);
	free(tmp);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
void (*free_fct)(void *))
{
	t_list	*list;

	if (!begin_list)
		return ;
	list = *begin_list;
	while (list && (*cmp)(list->data, data_ref) == 0)
		free_list(list, (*free_fct));
	*begin_list = list;
	while (list && list->next)
	{
		if ((*cmp)(list->next->data, data_ref) == 0)
			free_list(list, (*free_fct));
		else
			list = list->next;
	}
}
