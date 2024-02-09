/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:56:51 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 21:17:28 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char **argv)
{
	t_data	data;

	parsing(argc, argv, &data);
	if (data.error != 0)
		return (1);
	resolve(&data);
	if (argc == 3)
		free_split(data.dict);
	else
		free(data.dict);
}
