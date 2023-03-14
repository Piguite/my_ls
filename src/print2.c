/*
** EPITECH PROJECT, 2022
** siuu
** File description:
** print2
*/



#include "../include/my.h"

int maj_byte(unsigned int nb)
{
    return ((nb >> 8) & 0xff);
}

int min_byte(unsigned int nb)
{
    return (nb & 0xff);
}

void print_type(struct stat t_stat)
{
    if ((t_stat.st_mode & __S_IFMT) == __S_IFREG)
        my_printf("-");
    if ((t_stat.st_mode & __S_IFMT) == __S_IFSOCK)
        my_printf("s");
    if ((t_stat.st_mode & __S_IFMT) == __S_IFLNK)
        my_printf("l");
    if ((t_stat.st_mode & __S_IFMT) == __S_IFBLK)
        my_printf("b");
    if ((t_stat.st_mode & __S_IFMT) == __S_IFDIR)
        my_printf("d");
    if ((t_stat.st_mode & __S_IFMT) == __S_IFCHR)
        my_printf("c");
    if ((t_stat.st_mode & __S_IFMT) == __S_IFIFO)
        my_printf("p");
}

void put_error(char c)
{
    write(2, "ls: invalid option -- '", 23);
    write(2, &c, 1);
    write(2, "'\nTry 'ls --help' for more information.\n", 41);
    exit(84);
}
