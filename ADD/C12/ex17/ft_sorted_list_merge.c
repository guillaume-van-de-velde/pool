/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:40:31 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 20:40:43 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	swap_list(t_list **list, t_list **begin_list2, t_list **tmp)
{
	*tmp = *begin_list2;
	*begin_list2 = (*begin_list2)->next;
	(*tmp)->next = *list;
	*list = *tmp;
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	t_list	*list;
	t_list	*tmp;

	if (!begin_list1 || !begin_list2)
		return ;
	if (!*begin_list1)
		return (*begin_list1 = begin_list2, (void)0);
	list = *begin_list1;
	while (begin_list2 && (*cmp)(list->data, begin_list2->data) > 0)
		swap_list(&list, &begin_list2, &tmp);
	*begin_list1 = list;
	while (list && list->next && begin_list2)
	{
		if ((*cmp)(list->next->data, begin_list2->data) > 0)
			swap_list(&list->next, &begin_list2, &tmp);
		else
			list = list->next;
	}
	if (list && begin_list2 && (*cmp)(list->data, begin_list2->data) <= 0)
		list->next = begin_list2;
}
