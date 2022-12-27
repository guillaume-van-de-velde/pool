/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:01:41 by bberthod          #+#    #+#             */
/*   Updated: 2022/10/02 22:47:29 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct s_list
{
	int		nb;
	char	*val;
}	t_list;
int				ft_onlynumbers(char *str);
int				ft_strlen(char *str);
unsigned long	ft_atoi(char *str);
char			*ft_strdup(char *src);
void			ft_putstr(char *str);
char			*ft_getnb(int fd);
char			*ft_getval(int fd, char *c);
t_list			*process(char *file);

#endif
