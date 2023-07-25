void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
    int     i;
    char    *tmp;

    i = 0;
    if (!tab)
        return ;
    while (tab[i] && tab[i + 1])
    {
        if (cmp(tab[i], tab[i + 1]) > 0)
        {
            tmp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = tmp;
            i = 0;
        }
        else
            i++;
    }
}