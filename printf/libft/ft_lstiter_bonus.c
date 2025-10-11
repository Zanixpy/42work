#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *))
{
    t_list *current;

    if (!lst)
        return;
    current = lst;
    while (current != 0)
    {
        (*f)(current->content);
        current = current->next;
    } 
}

