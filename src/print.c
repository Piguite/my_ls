/*
** EPITECH PROJECT, 2022
** siuu
** File description:
** print
*/



#include "../include/my.h"

void printer_right(t_arg *lst)
{
    print_type(lst->stat);
    my_printf((lst->stat.st_mode & S_IRUSR) ? "r" : "-");
    my_printf((lst->stat.st_mode & S_IWUSR) ? "w" : "-");
    if (lst->stat.st_mode & S_ISUID)
        my_printf((lst->stat.st_mode & S_IXUSR) ? "s" : "S");
    else
        my_printf((lst->stat.st_mode & S_IXUSR) ? "x" : "-");
    my_printf((lst->stat.st_mode & S_IRGRP) ? "r" : "-");
    my_printf((lst->stat.st_mode & S_IWGRP) ? "w" : "-");
    if (lst->stat.st_mode & S_ISGID)
        my_printf((lst->stat.st_mode & S_IXGRP) ? "s" : "S");
    else
        my_printf((lst->stat.st_mode & S_IXGRP) ? "x" : "-");
    my_printf((lst->stat.st_mode & S_IROTH) ? "r" : "-");
    my_printf((lst->stat.st_mode & S_IWOTH) ? "w" : "-");
    if (lst->stat.st_mode & __S_ISVTX)
        my_printf((lst->stat.st_mode & S_IXOTH) ? "t" : "T");
    else
        my_printf((lst->stat.st_mode & S_IXOTH) ? "x" : "-");
    my_printf(". %d ", lst->stat.st_nlink);
}

void printer_right_folder(t_folder *lst)
{
    print_type(lst->stat);
    my_printf((lst->stat.st_mode & S_IRUSR) ? "r" : "-");
    my_printf((lst->stat.st_mode & S_IWUSR) ? "w" : "-");
    if (lst->stat.st_mode & S_ISUID)
        my_printf((lst->stat.st_mode & S_IXUSR) ? "s" : "S");
    else
        my_printf((lst->stat.st_mode & S_IXUSR) ? "x" : "-");
    my_printf((lst->stat.st_mode & S_IRGRP) ? "r" : "-");
    my_printf((lst->stat.st_mode & S_IWGRP) ? "w" : "-");
    if (lst->stat.st_mode & S_ISGID)
        my_printf((lst->stat.st_mode & S_IXGRP) ? "s" : "S");
    else
        my_printf((lst->stat.st_mode & S_IXGRP) ? "x" : "-");
    my_printf((lst->stat.st_mode & S_IROTH) ? "r" : "-");
    my_printf((lst->stat.st_mode & S_IWOTH) ? "w" : "-");
    if (lst->stat.st_mode & __S_ISVTX)
        my_printf((lst->stat.st_mode & S_IXOTH) ? "t" : "T");
    else
        my_printf((lst->stat.st_mode & S_IXOTH) ? "x" : "-");
    my_printf(". %d ", lst->stat.st_nlink);
}

void print_flag_l(t_arg *lst)
{
    struct passwd *pw = getpwuid(lst->stat.st_uid);
    struct group *gr = getgrgid(lst->stat.st_gid);

    printer_right(lst);
    pw != 0 ? my_printf("%s ", pw->pw_name) : my_printf("Unknown");
    gr != 0 ? my_printf("%s ", gr->gr_name) : my_printf("Unknown");
    if (S_ISCHR(lst->stat.st_mode) || S_ISBLK(lst->stat.st_mode))
        my_printf(
        "%d, %d ", maj_byte(lst->stat.st_rdev), min_byte(lst->stat.st_rdev));
    else
        my_printf("%d ", lst->stat.st_size);
    write(1, (ctime(&lst->stat.st_mtime) + 4),
    (my_strlen(ctime(&lst->stat.st_mtime)) - 13));
    my_printf(" ");
}

void print_flag_l_folder(t_render *render, t_folder *lst)
{
    struct passwd *pw = getpwuid(lst->stat.st_uid);
    struct group *gr = getgrgid(lst->stat.st_gid);

    if (render->f_l) {
        printer_right_folder(lst);
        pw != 0 ? my_printf("%s ", pw->pw_name) : my_printf("Unknown");
        gr != 0 ? my_printf("%s ", gr->gr_name) : my_printf("Unknown");
        if (S_ISCHR(lst->stat.st_mode) || S_ISBLK(lst->stat.st_mode))
            my_printf("%d, %d ", maj_byte(lst->stat.st_rdev),
            min_byte(lst->stat.st_rdev));
        else
            my_printf("%d ", lst->stat.st_size);
        write(1, (ctime(&lst->stat.st_mtime) + 4),
        (my_strlen(ctime(&lst->stat.st_mtime)) - 13));
        my_printf(" ");
    }
    my_printf("%s\n", render->name->path);
}

void print_arg(t_render *render, t_arg *lst, int size)
{
    char *current_path = NULL;
    int st = 0;

    while (lst) {
        if ((lst->file->path != current_path &&
            (render->f_big_r || size > 1) && st))
            my_printf("\n");
        if (lst->file->path != current_path && (render->f_big_r || size > 1))
            st = my_printf("%s:\n", lst->file->path);
        if (lst->file->path != current_path && render->f_l)
            my_printf("total %d\n", lst->file->blocks);
        current_path = lst->file->path;
        if (render->f_l && lst->file->name)
            print_flag_l(lst);
        if (lst->file->name)
            my_printf("%s\n", lst->file->name, lst->file->blocks);
        lst = lst->next;
    }
}
