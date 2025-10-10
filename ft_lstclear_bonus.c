#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *current;
    t_list *next;

    if (!lst)
        return;
    current = *lst;
    while (current != 0)
    {
        next = current->next;
        (*del)(current->content);
        free(current);
        current = next;   
    }
    *lst = 0;    
}
