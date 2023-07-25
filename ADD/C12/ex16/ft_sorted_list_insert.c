#include "ft_list.h"

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
    t_list  *list;
    void    *tmp;

    list = ft_create_elem(data);
    if (!list || !begin_list)
        return (free(list));
    if (!*begin_list)
        return (*begin_list = list, (void)0);
    list->next = *begin_list;
    *begin_list = list;
    while (list && list->next)
    {
        if ((*cmp)(list->data, list->next->data) > 0)
        {
            tmp = list->data;
            list->data = list->next->data;
            list->next->data = tmp;
            list = list->next;
        }
        else
            return ;
    }
}