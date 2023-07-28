#include "rush02.h"

void    keep_only_translate(t_data *data)
{
    int     i;
    int     j;
    char    *str;

    i = 0;
    while (data->dict[i])
    {
        j = 0;
        while (data->dict[i][j] >= '0' && data->dict[i][j] <= '9')
            j++;
        while (data->dict[i][j] == ' ')
            j++;
        j++;
        while (data->dict[i][j] == ' ')
            j++;
        str = ft_strdup(&data->dict[i][j]);
        if (!str)
            return (free_split(data->dict));
        free(data->dict[i]);
        data->dict[i] = str;
        i++;
    }
}

void    free_other_data(char **dict, int len)
{
    while (len > 40)
    {
        free(dict[len]);
        dict[len] = NULL;
        len--;
    }
}

void    swap_string(char **dict, int i, int j)
{
    char    *tmp;

    tmp = dict[i];
    dict[i] = dict[j];
    dict[j] = tmp;
}

int good_number_for_place(char *str_dict, char *good)
{
    size_t	i;

	i = 0;
	while (str_dict[i] && good[i])
	{
		if ((unsigned char)str_dict[i] - (unsigned char)good[i] != 0)
			return (0);
		i++;
	}
    if (good[i])
    {
        return (0);
    }
	if (str_dict[i] == ' ' || str_dict[i] == ':')
        return (1);
	return (0);
}

char    *thousand_plus(int place)
{
    if (place == 29)
        return ("1000");
    if (place == 30)
        return ("1000000");
    if (place == 31)
        return ("1000000000");
    if (place == 32)
        return ("1000000000000");
    if (place == 33)
        return ("1000000000000000");
    if (place == 34)
        return ("1000000000000000000");
    if (place == 35)
        return ("1000000000000000000000");
    if (place == 36)
        return ("1000000000000000000000000");
    if (place == 37)
        return ("1000000000000000000000000000");
    if (place == 38)
        return ("1000000000000000000000000000000");
    if (place == 39)
        return ("1000000000000000000000000000000000");
    if (place == 40)
        return ("1000000000000000000000000000000000000");
    return (NULL);
}

char *value_ref(int place)
{
    if (place <= 20)
        return (ft_itoa(place));
    if (place > 20 && place < 28)
        return (ft_itoa((place - 20) * 10 + 20));
    if (place == 28)
        return (ft_itoa(100));
    if (place > 28)
        return (ft_strdup(thousand_plus(place)));
    return (NULL);
}

int search_swapper(char **dict, int i)
{
    int     j;
    char    *good_number;

    j = i;
    good_number = value_ref(i);
    if (!good_number)
        return (-1);
    while (dict[j])
    {
        if (good_number_for_place(dict[j], good_number))
            return (free(good_number), j);
        j++;
    }
    free(good_number);
    return (-1);
}

int good_place(char *str, int i, int *error)
{
    char *good_number;

    if (i > 40)
        return (1);
    good_number = value_ref(i);
    if (!good_number)
        return (*error = 1, 0);
    if (!good_number_for_place(str, good_number))
        return (free(good_number), 0);
    free(good_number);
    return (1);
}

int good_line(char *str)
{
    int i;

    i = 0;
    if (!(str[i] >= '0' && str[i] <= '9'))
        return (0);
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    while (str[i] == ' ')
        i++;
    if (str[i] != ':')
        return (0);
    while (str[i] == ' ')
        i++;
    if (!str[i])
        return (0);
    return (1);
}

void    check_dict_lines(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->dict[i])
    {
        if (!good_line(data->dict[i]))
            return (free_split(data->dict), data->error = 1, (void)print_dict_error());
        i++;
    }
    i = 0;
    while (data->dict[i])
    {
        if (!good_place(data->dict[i], i, &data->error))
        {
            if (data->error != 0)
                return (free_split(data->dict), (void)print_error());
            j = search_swapper(data->dict, i);
            if (j == -1)
                return (free_split(data->dict), data->error = 1, (void)print_dict_error());
            swap_string(data->dict, i, j);
        }
        i++;
    }
    free_other_data(data->dict, i);
    keep_only_translate(data);
    if (data->error != 0)
        return (free_split(data->dict), data->error = 1, (void)print_error());
}