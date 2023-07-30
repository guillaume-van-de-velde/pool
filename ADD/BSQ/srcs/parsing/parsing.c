#include "bsq.h"

void    parsing(t_data *data, int num)
{
    if (num != -2)
        read_file(data, num);
    else
       read_stdin(data);
    check_file(data);
    if (data->error)
        print_error();
}