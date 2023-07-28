#include "rush02.h"

char    *ft_realloc(char *str, int actual)
{
    char *new;
    int     i;

    i = 0;
    new = malloc(actual + 1001);
    if (!new)
        return (free(str), NULL);
    new[actual + 1000] = '\0';
    while (str[i])
    {
        new[i] = str[i];
        i++;
    }
    free(str);
    return (new);
}

char    *get_file(int fd)
{
    char    *str;
    ssize_t reader;
    int     i;

    i = 0;
    str = malloc(1001);
    if (!str)
        return (print_error(), NULL);
    str[1000] = '\0';
    while ((reader = read(fd, &str[i], 100)) > 0)
    {
        i += reader;
        if (i % 1000 == 0)
        {
            str = ft_realloc(str, i);
            if (!str)
                return (print_error(), NULL);
        }
    }
    if (reader == -1)
        return (free(str), print_dict_error(), NULL);
    str[i] = '\0';
    return (str);
}

char    **get_dict(char *str)
{
    char    **dict;
    int     i;
    int     len;

    i = 0;
    dict = ft_split(str, '\n');
    free(str);
    if (!dict)
        return (print_error(), NULL);
    len = bigarray_len(dict);
    while (dict[i])
    {
        dict[i] = ft_strtrim(dict[i], " ");
        if (!dict[i])
            return (ft_free(dict, len), print_error(), NULL);
        i++;
    }
    return (dict);
}

void    parse_dict(t_data *data, char *file)
{
    int     fd;
    char    *str;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (data->error = 1, (void)print_dict_error());
    str = get_file(fd);
    if (!str)
        return (data->error = 1, close(fd), (void)0);
    data->dict = get_dict(str);
    if (!data->dict)
        return (data->error = 1, close(fd), (void)0);
    check_dict_lines(data);
    close(fd);
}