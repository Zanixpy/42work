/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:46:32 by omawele           #+#    #+#             */
/*   Updated: 2025/11/07 15:29:55 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
}

/*void proto(void *p)
{
    int *s = (int *) p;
    s = 0;
    (void)s;
}

int main(void)
{
    int a = 42;
    int b = 12;
    int c = 55654;
    t_list *p = ft_lstnew((void *)&a);
    ft_lstadd_front(&p, ft_lstnew((void *)&b));
    ft_lstadd_back(&p, ft_lstnew((void *)&c));
    ft_lstdelone((p->next)->next, &proto);
    printf("%d\n", * (int *) ft_lstlast(p)->content);
    free(p->next);
    free(p);
    return (0);
}*/
