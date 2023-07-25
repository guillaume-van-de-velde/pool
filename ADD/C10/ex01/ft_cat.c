#include <libgen.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#define BUFFER  30000

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    print_error(char *arg)
{
    char *str;

    str = strerror(errno);
    write(2, "cat: ", 5);
    write(2, arg, ft_strlen(arg));
    write(2, ": ", 2);
    write(2, str, ft_strlen(str));
    write(2, "\n", 1);
}

int ft_display_file(int fd)
{
    ssize_t reader;
    char    arr[BUFFER];

    reader = 1;
    while (reader > 0)
    {
        reader = read(fd, arr, BUFFER);
        if (reader == -1)
            return (0);
        if (reader > 0)
            write(1, arr, reader);
    }
    return (1);
}

int main(int argc, char **argv)
{
    int fd;
    int i;

    if (argc < 2)
    {
        ft_display_file(0);
        close(0);
    }
    i = 1;
    while (i < argc)
    {
        fd = open(argv[i], O_RDONLY);
        if (fd == -1)
            print_error(argv[i]);
        else
        {
            if (!ft_display_file(fd))
                print_error(argv[i]);
            close(fd);
        }
        i++;
    }
}