/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:31:25 by omawele           #+#    #+#             */
/*   Updated: 2026/02/02 20:38:40 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long ft_strlen(const char *s)
{
    int count;
    
    count = 0;
    while (*s) 
    {
        count++;
        s++;
    }
    return (count);
}

int	strcmp_int_limit(char *s)
{
	char	*unsigned_int_max;
	int		size;

	unsigned_int_max = "9223372036854775807";
	size = ft_strlen(s);
	if (size < 20)
		return (EXIT_SUCCESS);
	while (*unsigned_int_max)
	{
		if (*unsigned_int_max < *s)
			return (EXIT_FAILURE);
		unsigned_int_max++;
		s++;
	}
	return (EXIT_SUCCESS);
}
