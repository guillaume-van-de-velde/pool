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

void    print_list(t_list *list)
{
    while (list)
    {
        printf("%d\n", *(int *)list->data);
        list = list->next;
    }
}

int main()
{
    t_list *list;
    int a = 5;
    int b = 7;
    int c = 2;

    list = ft_create_elem(&a);
    list->next = ft_create_elem(&b);
    ft_list_push_back(&list, &c);
    print_list(list);
    free(list->next->next);
    free(list->next);
    free(list);
}