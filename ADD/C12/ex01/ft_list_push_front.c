#include "ft_list.h"

t_list *ft_create_elem(void *data)
{
    t_list *list;

    list = malloc(sizeof(t_list));
    if (!list)
        return (NULL);
    list->data = data;
    list->next = NULL;
    return (list);
}

void ft_list_push_front(t_list **begin_list, void *data)
{
    t_list  *new;

    if (!begin_list)
        return ;
    if (*begin_list)
    {
        new = ft_create_elem(data);
        new->next = *begin_list;
        *begin_list = new;
    }
    else
        *begin_list = ft_create_elem(data);
}

int main()
{
    t_list *list;
    int a = 5;
    int b = 7;

    list = ft_create_elem(&a);
    ft_list_push_front(&list, &b);
    printf("%d\n", *((int *)list->data));
    free(list->next);
    free(list);
}