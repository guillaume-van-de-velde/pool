/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:12:37 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 15:12:45 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	parsing(t_data *data, int num)
{
	if (num != -2)
		read_file(data, num);
	else
		read_stdin(data);
	check_file(data);
	if (data->error)
		print_error();
}
