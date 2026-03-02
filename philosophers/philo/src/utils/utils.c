/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 21:10:55 by omawele           #+#    #+#             */
/*   Updated: 2026/02/22 17:17:47 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/utils.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str <= 13 && *str >= 9))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

long get_time_in_milliseconds(void)
{
	struct timeval tv;

	if (gettimeofday(&tv,NULL) == -1)
		return (-1);
    return ((( long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
}