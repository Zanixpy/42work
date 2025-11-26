/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:39:10 by omawele           #+#    #+#             */
/*   Updated: 2025/11/26 09:45:38 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	ft_hexa(int pos, char mode)
{
	char	*hexa;

	hexa = "0123456789abcdefABCDEF";
	if (ft_isalpha(hexa[pos]) && mode == 'X')
		return (hexa[pos + 6]);
	return (hexa[pos]);
}
