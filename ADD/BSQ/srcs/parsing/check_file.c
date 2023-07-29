#include "bsq.h"

int check_length_and_chars(char **map, t_chars chars)
{
    int len;
    int i;
    int j;

    i = 0;
    len = ft_strlen(map[0]);
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != chars.nul || map[i][j] != chars.barrier)
                return (0);
            j++;
        }
        if (j != len)
            return (0);
        i++;
    }
    if (i != chars.line)
        return (0);
    return (1);
}

void    check_file(t_data *data)
{
    data->map = ft_split(data->file, '\n');
    if (!data->map)
        (free_all(data), exit(1));
    if (data->map && (!data->map[0] || !data->map[1]))
        return (free_map(data), (void)(error = 1));
    fill_chars(&data->chars, data->map[0]);
    if (data->chars.line == 0)
        return ((void)(error = 1));
    if (!check_length_and_chars(&data->map[1], data->chars))
        return ((void)(error = 1));
}