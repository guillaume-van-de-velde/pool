#include "rush02.h"

int	ft_isset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		start;
	int		end;
	char	*str;
	int		i;

	start = 0;
	end = ft_strlen(s1);
	i = 0;
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	while (end > start && ft_isset(s1[end - 1], set))
		end--;
	str = malloc(ft_strlen(&s1[start]) - ft_strlen(&s1[end]) + 1);
	if (!str)
		return (free(s1), NULL);
	while (start < end)
		str[i++] = s1[start++];
    free(s1);
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;
	int		len;

	len = ft_strlen(src);
	i = 0;
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

int	ft_len(long nb)
{
	int	len;

	len = 1;
	while (nb / 10 != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	int		i;
	char	*resultat;

	nb = n;
	len = ft_len(nb);
	i = 0;
	resultat = malloc(sizeof(char) * len + 1);
	if (!resultat)
		return (NULL);
	resultat[len--] = '\0';
	if (nb < 0 && ++i)
	{
		resultat[0] = '-';
		nb *= -1;
	}
	while (nb / 10 > 0 && len > i)
	{
		resultat[len] = '0' + (nb % 10);
		len--;
		nb /= 10;
	}
	resultat[len] = '0' + (nb % 10);
	return (resultat);
}