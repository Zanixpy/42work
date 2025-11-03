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

int main(void)
{
    char *str = "Test";
    int len = ft_strlen(str);
    printf("La size de str : %d\n", len);
    return (0);
}
