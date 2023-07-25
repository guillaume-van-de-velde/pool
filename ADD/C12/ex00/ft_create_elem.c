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

int main()
{
    t_list *list;
    int a = 5;

    list = ft_create_elem(&a);
    printf("%d\n", *((int *)list->data));
    free(list);
}