/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:42:54 by omawele           #+#    #+#             */
/*   Updated: 2025/11/07 15:28:45 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	p = *lst;
	if (p == 0)
	{
		*lst = new;
		return ;
	}
	while (p != 0)
	{
		if (p->next == 0)
		{
			p->next = new;
			return ;
		}
		p = p->next;
	}
}

/*int main(void)
{
    int a = 42;
    int b = 12;
    int c = 55654;
    t_list *p = ft_lstnew((void *)&a);
    ft_lstadd_front(&p, ft_lstnew((void *)&b));
    ft_lstadd_back(&p, ft_lstnew((void *)&c));
    printf("%d\n", * (int *) ft_lstlast(p)->content);
    free((p->next)->next);
    free(p->next);
    free(p);
    return (0);
}*/
