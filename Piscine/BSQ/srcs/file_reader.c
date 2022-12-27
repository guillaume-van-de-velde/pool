/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:29:21 by vchakhno          #+#    #+#             */
/*   Updated: 2022/10/05 22:26:10 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

t_resizable_str	default_str(void)
{
	t_resizable_str	str;

	str.capacity = 1024;
	str.str = malloc(sizeof(char) * str.capacity);
	str.size = 0;
	str.str[0] = '\0';
	return (str);
}

int	realloc_line(t_resizable_str *str)
{
	char	*temp;

	str->capacity *= 2;
	temp = malloc(sizeof(char) * str->capacity);
	if (!temp)
		return (0);
	ft_strcpy(temp, str->str);
	free(temp);
	str->str = temp;
	str->str[str->size] = '\0';
	return (1);
}

int	read_char(t_resizable_str *str, int fileno)
{
	char	size_read;

	if (str->size == str->capacity - 1)
		if (!realloc_line(str))
			return (0);
	size_read = read(fileno, str->str + str->size, 1);
	if (size_read <= 0)
		return (0);
	str->size++;
	str->str[str->size] = '\0';
	return (size_read);
}

t_resizable_str	get_line(int fileno)
{
	t_resizable_str	line;
	int				size_read;

	line = default_str();
	size_read = read_char(&line, fileno);
	while (size_read > 0 && line.str[line.size - 1] != '\n')
		size_read = read_char(&line, fileno);
	if (size_read > 0)
	{
		line.size--;
		line.str[line.size] = '\0';
	}
	return (line);
}
