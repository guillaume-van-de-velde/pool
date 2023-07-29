#include "bsq.h"

char    *realloc(char *str, int advance)
{
    char    *new;
    int     i;

    i = 0;
    new = malloc(advance + 1001);
    if (!new)
        return (free(str), NULL);
    new[advance + 1000] = '\0';
    while (str[i])
    {
        new[i] = str[i];
        i++;
    }
    return (new);
}

void    read_file(t_data *data, int num)
{
    int     i;
    ssize_t reader;

    i = 0;
    data->file = malloc(1001);
    if (!data->file)
        (free(data->fds), exit(1));
    data->file[1000] = '\0';
    while ((reader = read(data->fds[num], &data->file[i], 1000)))
    {
        i += reader;
        if (reader < 1000)
            break ;
        else
            data->file = ft_realloc(data->file, i);
        if (!data->file)
            (free(data->fds), exit(1));
    }
    if (reader == -1)
        data->error = 1;
    data->file[i] = '\0';
}