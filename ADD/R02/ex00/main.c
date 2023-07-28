#include "rush02.h"

int main(int argc, char **argv)
{
    t_data  data;

    parsing(argc, argv, &data);
    if (data.error != 0)
        return (1);
    resolve(&data);
    if (argc == 3)
        free_split(data.dict);
    else
        free(data.dict);
}