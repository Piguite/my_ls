/*
** EPITECH PROJECT, 2022
** siuu
** File description:
** sort_folder
*/



#include "../include/my.h"

void my_rev_list_folder(t_folder **begin)
{
    t_folder *next = NULL;
    t_folder *previous = NULL;
    t_folder *atm = NULL;

    atm = *begin;
    while (atm) {
        next = atm->next;
        atm->next = previous;
        previous = atm;
        atm = next;
    }
    *begin = previous;
}

void my_swap_list(t_folder **a, t_folder **b)
{
    char *tmp_s;
    struct stat tmp;

    tmp_s = (*a)->path;
    (*a)->path = (*b)->path;
    (*b)->path = tmp_s;
    tmp = (*a)->stat;
    (*a)->stat = (*b)->stat;
    (*b)->stat = tmp;
}

int my_sort(t_folder *tmp, t_folder *atm, int i, int time)
{
    struct stat t_stat;
    struct stat tmp_stat;

    stat(tmp->path, &tmp_stat);
    stat(atm->path, &t_stat);
    if (time == 0) {
        if (my_strcmp((char *)tmp->path, (char *)atm->path) > 0) {
            my_swap_list(&tmp, &atm);
            return (-1);
        }
        return (i);
    }
    if (time == 1) {
        if (tmp_stat.st_mtime < t_stat.st_mtime) {
            my_swap_list(&tmp, &atm);
            return (-1);
        }
    }
    return (i);
}

void my_sort_list_alpha_folder(t_folder **begin, int time)
{
    t_folder *tmp = NULL;
    t_folder *atm = NULL;
    int i = -1;
    if (!(*begin) || !(*begin)->next)
        return;

    while (++i < my_list_size_bis((*begin))) {
        tmp = *begin;
        atm = tmp->next;
        while (atm) {
            i = my_sort(tmp, atm, i, time);
            tmp = tmp->next;
            atm = atm->next;
        }
    }
}

void sort_folder_flags(t_render *render, t_folder **lst)
{
    my_sort_list_alpha_folder(lst, 0);
    if (render->f_t)
        my_sort_list_alpha_folder(lst, 1);
    if (render->f_r) {
        my_rev_list_folder(lst);
    }
}
