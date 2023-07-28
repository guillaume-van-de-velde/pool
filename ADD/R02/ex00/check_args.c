#include "rush02.h"

int valide_number(char *str)
{
    int i;

    i = 0;
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    if (i == ft_strlen(str) && i < 40 && !(str[0] == '0' && i != 1) && i != 0)
        return (1);
    return (0);
}

void check_args(int argc, char **argv, t_data *data)
{
    if (argc != 2 && argc != 3)
        return (data->error = 1, (void)print_error());
    if (argc == 2)
    {
        if (!valide_number(argv[1]))
            return (data->error = 1, (void)print_error());
        return (data->number = argv[1], (void)0);
    }
    else
    {
        if (!valide_number(argv[2]))
            return (data->error = 1, (void)print_error());
        return (data->number = argv[2], (void)0);
    }
}