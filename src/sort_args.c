/*
** EPITECH PROJECT, 2022
** siuu
** File description:
** sort_args
*/

#include "../include/my.h"

void my_swap_list_arg(t_arg **a, t_arg **b)
{
    file *tmp_f;
    struct stat tmp_s;

    tmp_f = (*a)->file;
    (*a)->file = (*b)->file;
    (*b)->file = tmp_f;
    tmp_s = (*a)->stat;
    (*a)->stat = (*b)->stat;
    (*b)->stat = tmp_s;
}

int my_sort_arg(t_arg *tmp, t_arg *atm, int i, int time)
{
    if (time == 0) {
        if (my_strcmp((char *)tmp->file->name, (char *)atm->file->name) > 0) {
            my_swap_list_arg(&tmp, &atm);
            return (-1);
        }
    }
    if (time == 1) {
        if (tmp->stat.st_mtime < atm->stat.st_mtime) {
            my_swap_list_arg(&tmp, &atm);
            return (-1);
        }
    }
    return (i);
}

void my_sort_list_alpha_arg(t_arg **begin, int time)
{
    t_arg *tmp = NULL;
    t_arg *atm = NULL;
    int i = -1;

    if (!(*begin) || !(*begin)->next)
        return;
    while (++i < my_list_size((*begin))) {
        tmp = *begin;
        atm = tmp->next;
        while (atm) {
            i = my_sort_arg(tmp, atm, i, time);
            tmp = tmp->next;
            atm = atm->next;
        }
    }
}

void my_rev_list_arg(t_arg **begin)
{
    t_arg *next = NULL;
    t_arg *previous = NULL;
    t_arg *atm = NULL;

    atm = *begin;
    while (atm) {
        next = atm->next;
        atm->next = previous;
        previous = atm;
        atm = next;
    }
    *begin = previous;
}

void sort_arg_flags(t_render *render, t_arg **lst)
{
    my_sort_list_alpha_arg(lst, 0);
    if (render->f_t)
        my_sort_list_alpha_arg(lst, 1);
    if (render->f_r) {
        my_rev_list_arg(lst);
    }
}
