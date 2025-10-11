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
    ft_lstclear(&p, &proto);
    if (p == 0)
    {
        printf("Done\n");
    }else
        printf("Rater\n");
    //printf("%d\n", * (int *) (p->next)->next->content);
    //printf("%d\n", * (int *) (p->next)->content);
    //printf("%d\n", * (int *) p->content);  
    return (0);
}*/
