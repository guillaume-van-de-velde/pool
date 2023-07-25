int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
    int rise;
    int decrease;

	i = 0;
    rise = 0;
    decrease = 0;
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			rise++;
        if (f(tab[i], tab[i + 1]) <= 0)
			decrease++;
		i++;
	}
    if (rise == i || decrease == i)
    {
        return (1);
    }
	return (0);
}