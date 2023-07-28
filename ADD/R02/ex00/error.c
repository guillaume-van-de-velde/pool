#include "rush02.h"

int print_error()
{
    write(2, "Error\n", 6);
    return (0);
}

int print_dict_error()
{
    write(2, "Dict Error\n", 11);
    return (0);
}