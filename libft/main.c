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
    char s[30] = "Hey every";
    printf("sizeof s : %d\n", (int) sizeof(s));
    printf("lengthof s : %d\n", (int) ft_strlen(s));

    return 0;
}
