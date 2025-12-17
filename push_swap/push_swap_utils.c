/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:45:15 by omawele           #+#    #+#             */
/*   Updated: 2025/12/17 21:59:44 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int strcmp_int_limit(char *s, int mode)
{
    char *int_max_min;
    int size;

    if (mode)
        int_max_min = "2147483647";
    else
        int_max_min = "-2147483648";
    size = ft_strlen(s);
    if ((mode == 0 && size <= 10) || (mode == 1 && size <= 9))
        return (0);
    if (mode)
    {
        while (*int_max_min)
        {
            if (*int_max_min < *s)
                return (1);
            int_max_min++;
            s++;
        }   
    }
    return (0);
}
