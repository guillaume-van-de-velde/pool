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
        printf("%s\n", (char *)list->data);
        list = list->next;
    }
}

int main()
{
    char *strs[10] = {"hello", "ca va", "comment", NULL};
    t_list  *list;

    list = ft_list_push_strs(3, strs);
    print_list(list);
    // free(list->next->next);
    // free(list->next);
    // free(list);
}