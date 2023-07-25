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
        list = ft_create_elem(data);
}