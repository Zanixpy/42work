#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *p;

    p = (t_list *) malloc(sizeof(t_list));
    if (p == 0)
        return (0);
    p->content = content;
    p->next = 0;
    return (p);
}

/*int main(void)
{
    int a = 42;
    t_list *p = ft_lstnew((void *)&a);
    printf("%d\n", * (int *)p->content);
    free(p);
    return (0);
}*/