/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:16:37 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/10 17:09:40 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>

# include "structures.h"
# include "parsing.h"
# include "resolve.h"

int		ft_strlen(char *str);

void	print_error(void);

void	free_split(char **split);
void	free_map(t_data *data);
void	free_all(t_data *data);

void	set_chars(t_chars *chars);
void	set_data(t_data *data);

void	bsq_for_file(t_data *data);
int		main(int argc, char **argv);

#endif