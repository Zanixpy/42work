#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    t_list *p;

    p = lst;
    while (p != 0)
    {
        if (p->next == 0)
            return (p);
        p = p->next;
    }
    return (0);
}

/*int main(void)
{
    int a = 42;
    int b = 12;
    int c = 55654;
    t_list *p = ft_lstnew((void *)&a);
    ft_lstadd_front(&p, ft_lstnew((void *)&b));
    ft_lstadd_front(&p, ft_lstnew((void *)&c));
    printf("%d\n", * (int *) ft_lstlast(p)->content);
    free((p->next)->next);
    free(p->next);
    free(p);
    return (0);
}*/