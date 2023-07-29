#include "bsq.h"

void    set_chars(t_chars *chars)
{
    chars->line = 0;
    chars->nul = '\0';
    chars->barrier = '\0';
    chars->full = '\0';
}

void    set_data(t_data *data)
{
    set_chars(&data->chars);
    data->fd = NULL;
    data->file = NULL;
    data->map = NULL;
}