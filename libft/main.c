/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:55:27 by omawele           #+#    #+#             */
/*   Updated: 2025/11/03 16:55:32 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>
#include <limits.h>


int main(void)
{
    printf("\nLe result (atoi) : %d\n", atoi("-2147483648 "));
    printf("\nLe result (ft_atoi) : %d\n", ft_atoi("-2147483648 "));
    return 0;
}
