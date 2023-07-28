#include "rush02.h"

void    set_data(t_data *data)
{
    data->dict = NULL;
    data->number = NULL;
    data->error = 0;
    data->writted = 0;
    data->no_print = 0;
}

void    parsing(int argc, char **argv, t_data *data)
{
    set_data(data);
    check_args(argc, argv, data);
    if (data->error != 0)
        return ;
    if (argc == 3)
        parse_dict(data, argv[1]);
    else
        create_dict(data);
}