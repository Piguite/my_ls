/*
** EPITECH PROJECT, 2022
** siuu
** File description:
** args
*/



#include "../include/my.h"

t_arg *my_create_elem_arg(struct dirent *data, struct stat stat, char *path)
{
    t_arg *new;
    file *elem;

    new = malloc(sizeof(t_arg));
    elem = malloc(sizeof(file));
    if (!new)
        return (NULL);
    if (data) {
        elem->name = my_strdup(data->d_name);
        elem->type = data->d_type;
    }
    elem->blocks = 0;
    if (!data)
        elem->name = NULL;
    elem->path = path;
    elem->already_op = 0;
    new->file = elem;
    new->stat = stat;
    new->next = NULL;
    return (new);
}

void my_list_push_arg(t_arg **b_l, struct dirent *d, struct stat s, char *p)
{
    t_arg *tmp;

    if (!(*b_l)) {
        *b_l = my_create_elem_arg(d, s, p);
        return;
    }
    tmp = *b_l;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = my_create_elem_arg(d, s, p);
}

void my_lstclear_arg(t_arg **lst)
{
    t_arg *tmp;

    if (!lst)
        return;
    while (*lst) {
        tmp = (*lst)->next;
        free((*lst)->file->name);
        free((*lst)->file);
        free(*lst);
        *lst = tmp;
    }
}

int my_list_size(t_arg *begin)
{
    if (!begin)
        return (0);
    return (1 + my_list_size(begin->next));
}
