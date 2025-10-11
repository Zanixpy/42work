#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *tab;
    t_list *tmp;
    t_list *current;
    void *result;

    current = lst;
    result = (*f)(current->content);
    tab = ft_lstnew(result);
    if (tab == 0)
        return (0);
    current = current->next;
    while (current != 0)
    {
        result = (*f)(current->content);
        tmp = ft_lstnew(result);
        if (tmp == 0)
        {
            ft_lstclear(&tab, del);
            return (0);
        }
        ft_lstadd_back(&tab,tmp);
        current = current->next;        
    }
    return (tab);
}

void *proto(void *t)
{
    int *p = (int *)t;
    *p += 10;
    return ((void *)p);
}

void prot(void *s)
{
    (void)s;
}

int main(void)
{
    int a = 42;
    int b = 12;
    int c = 55654;
    t_list *p = ft_lstnew((void *)&a);
    ft_lstadd_front(&p, ft_lstnew((void *)&b));
    ft_lstadd_front(&p, ft_lstnew((void *)&c));
    t_list *result = ft_lstmap(p, &proto, &prot);
    printf("%d\n", * (int *)result->content);
    ft_lstclear(&p, &prot);
    ft_lstclear(&result, &prot);
    return (0);
}