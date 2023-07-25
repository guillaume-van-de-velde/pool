#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
    int i;

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

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
    unsigned int    i;

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

void ft_list_reverse(t_list **begin_list)
{
    t_list  *list;
    t_list  *tmp;
    int     size;
    int     i;

    size = ft_list_size(*begin_list);
    if (size == 0 || size == 1)
        return ;
    i = 0;
    list = *begin_list;
    *begin_list = ft_list_at(*begin_list, size - 1);
    while (i < size - 1)
    {
        tmp = list->next;
        list->next = (*begin_list)->next;
        (*begin_list)->next = list;
        list = tmp;
        i++;
    }
}