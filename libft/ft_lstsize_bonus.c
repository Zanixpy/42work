/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:22:18 by omawele           #+#    #+#             */
/*   Updated: 2025/11/06 14:24:22 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		n;

	if (!lst)
		return (0);
	n = 0;
	current = lst;
	while (current != 0)
	{
		n++;
		current = current->next;
	}
	return (n);
}

/*int main(void)
{
    int a = 42;
    int b = 12;
    int c = 55654;
    t_list *p = ft_lstnew((void *)&a);
    ft_lstadd_front(&p, ft_lstnew((void *)&b));
    ft_lstadd_front(&p, ft_lstnew((void *)&c));
    printf("%d\n", ft_lstsize(p));
    free((p->next)->next);
    free(p->next);
    free(p);
    return (0);
}*/
