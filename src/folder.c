/*
** EPITECH PROJECT, 2022
** siuu
** File description:
** folder
*/



#include "../include/my.h"

t_folder *my_create_elem_folder(char *data, struct stat t_stat)
{
    t_folder *new;

    new = malloc(sizeof(t_folder));
    if (!new)
        return (NULL);
    new->path = data;
    new->stat = t_stat;
    new->next = NULL;
    return (new);
}

void my_list_push_back_folder(t_folder **b_l, char *data, struct stat t_stat)
{
    t_folder *tmp;

    if (!(*b_l)) {
        *b_l = my_create_elem_folder(data, t_stat);
        return;
    }
    tmp = *b_l;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = my_create_elem_folder(data, t_stat);
}

void my_lstclear_folder(t_folder **lst)
{
    t_folder *tmp;

    if (!lst)
        return;
    while (*lst) {
        tmp = (*lst)->next;
        free((*lst)->path);
        free(*lst);
        *lst = tmp;
    }
}

int my_list_size_bis(t_folder *begin)
{
    if (!begin)
        return (0);
    return (1 + my_list_size_bis(begin->next));
}
