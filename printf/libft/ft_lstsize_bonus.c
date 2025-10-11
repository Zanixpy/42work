#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int n;
    t_list *current;

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
