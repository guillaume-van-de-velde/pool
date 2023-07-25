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

int main()
{
    t_list *list;
    int a = 5;
    int b = 7;

    list = ft_create_elem(&a);
    list->next = malloc(sizeof(t_list));
    list->next->data = &b;
    list->next->next = NULL;
    printf("%d\n", ft_list_size(list));
    free(list->next);
    free(list);
}