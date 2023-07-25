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