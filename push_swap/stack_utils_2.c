/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:07:17 by omawele           #+#    #+#             */
/*   Updated: 2025/12/19 17:40:06 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stkempty(t_stack *p)
{
    if (stksize(p) == 0)
        return (1);
    return (0);  
}

t_stack	*stkbeflast(t_stack *stk)
{
	if (!stk)
		return (NULL);
	while (stk != NULL)
	{
		if (stk->next->next == NULL)
			return (stk);
		stk = stk->next;
	}
	return (NULL);
}