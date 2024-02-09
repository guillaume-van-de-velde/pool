/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:56:39 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 21:16:07 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*fill_dict_create_hundred(int index)
{
	if (index == 28)
		return ("hundred");
	if (index == 29)
		return ("thousand");
	if (index == 30)
		return ("million");
	if (index == 31)
		return ("billion");
	if (index == 32)
		return ("trillion");
	if (index == 33)
		return ("quadrillion");
	if (index == 34)
		return ("quintillion");
	if (index == 35)
		return ("sextillion");
	if (index == 36)
		return ("septillion");
	if (index == 37)
		return ("octillion");
	if (index == 38)
		return ("nontillion");
	if (index == 39)
		return ("decillion");
	if (index == 40)
		return ("undecillion");
	return (NULL);
}

char	*fill_dict_create_twenty(int index)
{
	if (index == 20)
		return ("twenty");
	if (index == 21)
		return ("thirty");
	if (index == 22)
		return ("forty");
	if (index == 23)
		return ("fifty");
	if (index == 24)
		return ("sixty");
	if (index == 25)
		return ("seventy");
	if (index == 26)
		return ("eighty");
	if (index == 27)
		return ("ninety");
	return (fill_dict_create_hundred(index));
}

char	*fill_dict_create_ten(int index)
{
	if (index == 10)
		return ("ten");
	if (index == 11)
		return ("eleven");
	if (index == 12)
		return ("twelve");
	if (index == 13)
		return ("thirteen");
	if (index == 14)
		return ("fourteen");
	if (index == 15)
		return ("fiveteen");
	if (index == 16)
		return ("sixteen");
	if (index == 17)
		return ("seventeen");
	if (index == 18)
		return ("eighteen");
	if (index == 19)
		return ("nineteen");
	return (fill_dict_create_twenty(index));
}

char	*fill_dict_create(int index)
{
	if (index == 0)
		return ("zero");
	if (index == 1)
		return ("one");
	if (index == 2)
		return ("two");
	if (index == 3)
		return ("three");
	if (index == 4)
		return ("four");
	if (index == 5)
		return ("five");
	if (index == 6)
		return ("six");
	if (index == 7)
		return ("seven");
	if (index == 8)
		return ("eight");
	if (index == 9)
		return ("nine");
	return (fill_dict_create_ten(index));
}

void	create_dict(t_data *data)
{
	int	i;

	i = 0;
	data->dict = malloc(sizeof(char *) * 42);
	if (!data->dict)
		return (data->error = 1, (void)print_error());
	while (i < 41)
	{
		data->dict[i] = fill_dict_create(i);
		i++;
	}
	data->dict[i] = NULL;
}
