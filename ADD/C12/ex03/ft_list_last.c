#include "ft_list.h"

t_list  *ft_list_last(t_list *begin_list)
{
    if (!begin_list)
        return (NULL);
    while (begin_list->next)
        begin_list = begin_list->next;
    return (begin_list);
}

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

int main()
{
    t_list *list;
    int a = 5;
    int b = 7;

    list = ft_create_elem(&a);
    list->next = malloc(sizeof(t_list));
    list->next->data = &b;
    list->next->next = NULL;
    printf("%d\n", *(int *)ft_list_last(list)->data);
    free(list->next);
    free(list);
}