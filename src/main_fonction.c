/*
** EPITECH PROJECT, 2022
** siuu
** File description:
** main_fonction
*/



#include "../include/my.h"

t_arg *my_ls(t_render *tmp)
{
    t_arg *lst = NULL;

    get_folder_info(tmp->name->path, &lst, tmp);
    return (lst);
}

int my_ls_main(char **av)
{
    struct stat t_stat;
    t_render *render = get_flags(av, t_stat, -1, 0);
    t_render *tmp = render;
    t_arg *lst_main = NULL;
    int size = my_list_size_bis(render->name);

    if (render->f_d) {
        while (render->name) {
            print_flag_l_folder(render, render->name);
            render->name = render->name->next;
        }
        return (0);
    }
    while (tmp->name) {
        my_concat_list(&lst_main, my_ls(tmp));
        tmp->name = tmp->name->next;
    }
    print_arg(tmp, lst_main, size);
    my_lstclear_arg(&lst_main);
    return (render->return_value);
}
