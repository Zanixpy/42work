#include "libft.h"
#include <stdio.h>

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *p;

  
    p = *lst;
    if (p == 0)
    {
        *lst = new;
        return;
    }
    while (p != 0)
    {
        if (p->next == 0)
        {
            p->next = new;
            return;
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
