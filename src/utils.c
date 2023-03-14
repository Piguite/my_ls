/*
** EPITECH PROJECT, 2022
** siuu
** File description:
** utils
*/



#include "../include/my.h"

char *my_strdup(char *src)
{
    int i = 0;
    char *cpy;

    if (!src)
        return (NULL);
    if (!(cpy = malloc(sizeof(char) * my_strlen(src) + 1)))
        return (NULL);
    while (src[i]) {
        cpy[i] = src[i];
        i++;
    }
    cpy[i] = '\0';
    return (cpy);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while ((s1[i]) == (s2[i]) && s1[i] && s2[i])
        i++;
    return ((s1[i]) - (s2[i]));
}

char *my_advanced_strcat(char *s1, char *s2)
{
    char *res = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2)) + 2);
    int i = -1;
    int j = -1;

    while (s1[++i])
        res[i] = s1[i];
    res[i++] = '/';
    while (s2[++j])
        res[i + j] = s2[j];
    res[i + j] = '\0';
    return (res);
}

void my_concat_list(t_arg **begin1, t_arg *begin2)
{
    if (!(*begin1))
        *begin1 = begin2;
    else if ((*begin1)->next)
        my_concat_list(&(*begin1)->next, begin2);
    else
        (*begin1)->next = begin2;
}

int print_perror(void *error, char *by_the_way, t_render *render)
{
    struct stat t_stat;
    int res = stat(by_the_way, &t_stat);

    if (res == 0 && !S_ISDIR(t_stat.st_mode)) {
        print_flag_l_folder(render, render->name);
        return (0);
    }
    if (error == 0 || res == -1) {
        if (S_ISDIR(t_stat.st_mode))
            write(2, "ls: cannot open directory '", 27);
        else
            write(2, "ls: cannot access '", 19);
        write(2, by_the_way, my_strlen(by_the_way));
        write(2, "': ", 3);
        perror(error);
        render->return_value = 84;
        return (0);
    }
    return (1);
}
