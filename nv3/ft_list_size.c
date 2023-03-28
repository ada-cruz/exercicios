/*Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;*/
#include "ft_list.h"
#include <stdio.h>

int	ft_list_size(t_list *begin_list)
{
    int i;
    t_list *aux;

    aux = begin_list;
    i = 0;
    while(aux != NULL)
    {
        aux = aux->next;
        i++;
    }
    return (i);

}

// t_list *add_no(void *content)
// {
//     t_list *temp;

//     temp = malloc(sizeof(t_list));
//     temp->data = content;
//     temp->next = NULL;
//     return (temp);
// }

// void    add_back(t_list **lista, t_list *no)
// {
//     t_list *aux;

//     if (lista == NULL)
//         return ;
//     if (*lista == NULL)
//     {
//         *lista = no;
//         return ;
//     }
//     aux = *lista;
//     while (aux->next != NULL)
//         aux = aux->next;
//     aux->next = no;
// }

// int main(void)
// {
//     t_list *list;
    
//     list = NULL;
//     add_back(&list, add_no("aurora"));
//     //add_back(&list, add_no("Renan"));
//     //add_back(&list, add_no("aaaaa"));

//     printf("%s\n", (char *)list->data);
//    // printf("%s\n", (char *)list->next->data);
//     //printf("%s\n", list->next->next->data);

//     printf("%d\n", ft_list_size(list));

// }