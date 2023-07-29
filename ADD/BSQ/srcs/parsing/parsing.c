#include "bsq.h"

void    parsing(t_data *data, int num)
{
    read_file(data, num);
    check_file(data);
    if (data->error)
        print_error();
}