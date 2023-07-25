#include "ft_list.h"

void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
    t_list  *list;

    if (!begin_list1)
        return ;
    if (!*begin_list1)
        return (*begin_list1 = begin_list2, (void)0);
    list = *begin_list1;
    while (list && list->next)
        list = list->next;
    list->next = begin_list2;
}