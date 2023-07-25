int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] - s2[i] == 0)
		i++;
	return (s1[i] - s2[i]);
}

void ft_sort_string_tab(char **tab)
{
    int     i;
    char    *tmp;

    i = 0;
    if (!tab)
        return ;
    while (tab[i] && tab[i + 1])
    {
        if (ft_strcmp(tab[i], tab[i + 1]) > 0)
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