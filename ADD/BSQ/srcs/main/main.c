#include "bsq.h"

void    bsq_for_file(t_data *data)
{
    int i;

    i = 0;
    while (data->fds[i])
    {
        if (data->fds[i] != -1)
        {
            parsing(&data, i);
            if (data->error)
                resolve(&data);
            free_map(&data);
            set_data(&data);
        }
        else
            print_error();
        i++;
    }
}

int main(int argc, char **argv)
{
    t_data  data;

    set_data(&data);
    check_args(argc, argv, &data);
    if (data->fds)
        bsq_for_file(&data);
    else
        (read_stdin(&data), parsing(&data, -1), resolve(&data));
}