#include "bsq.h"

void    check_args(int argc, char **argv, t_data *data)
{
    int i;

    i = 0;
    if (argc < 2)
        return ;
    data->fds = malloc(sizeof(int) * argc);
    if (!data->fds)
        exit(1);
    data->fds[argc - 1] = 0;
    while (i < argc - 1)
    {
        data->fds[i] = open(argv[i + 1], O_RDONLY);
        i++;
    }
}