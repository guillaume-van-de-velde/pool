#include "ft_list.h"

void    ft_list_push_back(t_list **begin_list, void *data)
{
    t_list  *list;

    if (!begin_list)
        return ;
    list = *begin_list;
    if (list)
    {
        while (list->next)
            list = list->next;
        list->next = ft_create_elem(data);    
    }
    else
        *begin_list = ft_create_elem(data);
}

t_list  *ft_list_push_strs(int size, char **strs)
{
    t_list  *list;

    list = NULL;
    while (size > 0)
    {
        ft_list_push_back(&list, strs[size - 1]);
        size--;
    }
    return (list);
}