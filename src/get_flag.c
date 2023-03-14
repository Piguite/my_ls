/*
** EPITECH PROJECT, 2022
** siuu
** File description:
** get_flag
*/



#include "../include/my.h"

t_render *init_render(void)
{
    t_render *render = malloc(sizeof(t_render));

    render->nb.blocks = 0;
    render->nb.ct = 0;
    render->f_big_r = 0;
    render->f_d = 0;
    render->f_l = 0;
    render->f_r = 0;
    render->f_t = 0;
    render->return_value = 0;
    return (render);
}

void push_folder(t_render *render, char *s)
{
    struct stat t_stat;

    stat(s, &t_stat);
    my_list_push_back_folder(&render->name, s, t_stat);
}

int flags(t_render *render, char *s, int i)
{
    if (s[0] != '-') {
        push_folder(render, s);
        return (-1);
    }
    while (s[++i]) {
        if (!in_charset(s[i], "lrdRt"))
            return (s[i]);
        if (s[i] == 'l')
            render->f_l++;
        if (s[i] == 'r')
            render->f_r++;
        if (s[i] == 'd')
            render->f_d++;
        if (s[i] == 'R')
            render->f_big_r++;
        if (s[i] == 't')
            render->f_t++;
    }
    return (-1);
}

t_render *get_flags(char **av, struct stat t_stat, int i, int error)
{
    t_render *render = init_render();
    stat(".", &t_stat);

    if (!av[1]) {
        render->name = my_create_elem_folder(".", t_stat);
        return (render);
    }
    av = &av[1];
    while (av[++i]) {
        error = flags(render, av[i], 0);
        if (error != -1) {
            put_error(error);
            exit(84);
        }
    }
    if (!render->name)
        render->name = my_create_elem_folder(".", t_stat);
    sort_folder_flags(render, &render->name);
    return (render);
}
