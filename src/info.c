/*
** EPITECH PROJECT, 2022
** siuu
** File description:
** info
*/



#include "../include/my.h"

void folder_info_side_kick(t_arg **lst, t_arg **lst_mn, t_render *r, int b)
{
    sort_arg_flags(r, lst);
    (*lst)->file->blocks = b / 2;
    my_concat_list(lst_mn, *lst);
    enumerating_lst(*lst, lst_mn, r);
}

t_arg *get_folder_info(char *path, t_arg **lst_main, t_render *render)
{
    DIR *fd = opendir(path);
    struct dirent *file;
    struct stat t_stat;
    t_arg *lst = NULL;

    if (!print_perror(fd, path, render))
        return (NULL);
    while ((file = readdir(fd))) {
        if (file->d_name[0] == '.')
            continue;
        render->nb.ct++;
        stat(my_advanced_strcat(path, file->d_name), &t_stat);
        my_list_push_arg(&lst, file, t_stat, path);
        render->nb.blocks += t_stat.st_blocks;
    }
    if (render->nb.ct == 0)
        lst = my_create_elem_arg(file, t_stat, path);
    folder_info_side_kick(&lst, lst_main, render, render->nb.blocks);
    closedir(fd);
    return (lst);
}

void enumerating_lst(t_arg *lst, t_arg **lst_main, t_render *render)
{
    while (lst) {
        render->nb.ct = 0;
        render->nb.blocks = 0;
        if (lst->file->type == 4 && !lst->file->already_op &&
        render->f_big_r) {
            get_folder_info(
            my_advanced_strcat(lst->file->path, lst->file->name), lst_main,
            render);
            lst->file->already_op++;
        }
        lst = lst->next;
    }
}
