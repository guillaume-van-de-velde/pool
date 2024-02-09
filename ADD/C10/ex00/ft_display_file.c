/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:52:30 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 19:52:55 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	ft_display_file(int fd)
{
	ssize_t	reader;
	char	c;

	reader = 1;
	while (reader > 0)
	{
		reader = read(fd, &c, 1);
		if (reader == -1)
			return (0);
		if (reader == 1)
			write(1, &c, 1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
		return (write(2, (char *)"File name missing.\n", 19), 1);
	if (argc > 2)
		return (write(2, (char *)"Too many arguments.\n", 20), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (write(2, (char *)"Cannot read file.\n", 18), 1);
	if (!ft_display_file(fd) || close(fd) == -1)
		return (1);
}
