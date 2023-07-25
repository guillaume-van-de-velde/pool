#include "ft_list.h"

void ft_list_sort(t_list **begin_list, int (*cmp)())
{
    t_list  *list;
    void    *tmp;

    if (!begin_list)
        return ;
    list = *begin_list;
    while (list && list->next)
    {
        if ((*cmp)(list->data, list->next->data) > 0)
        {
            tmp = list->data;
            list->data = list->next->data;
            list->next->data = tmp;
            list = *begin_list;
        }
        else
            list = list->next;
    }
}