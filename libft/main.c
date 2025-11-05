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
    printf("Le resultat (strtrim) : %s\n", strtrim("   xxx   xxx", " x"));
    printf("Le resultat (ft_strtrim) : %s\n", ft_strtrim("   xxx   xxx", " x"));
    return 0;
}
