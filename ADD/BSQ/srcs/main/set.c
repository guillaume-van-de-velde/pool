/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:10:36 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 15:10:45 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	set_chars(t_chars *chars)
{
	chars->line = 0;
	chars->nul = '\0';
	chars->barrier = '\0';
	chars->full = '\0';
}

void	set_data(t_data *data)
{
	set_chars(&data->chars);
	data->fds = NULL;
	data->file = NULL;
	data->map = NULL;
	data->error = 0;
}
