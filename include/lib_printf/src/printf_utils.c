/*
** EPITECH PROJECT, 2022
** siuu
** File description:
** my_printf_utils
*/



#include "../include/my.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int my_strlen(char *str)
{
    int i = 0;

    if (str == NULL)
        return (4);
    while (str[i])
        i++;
    return (i);
}

int my_putstr(char *s, int max)
{
    int i = -1;
    int j = -1;

    if (max == 0)
        while (s[++i])
            write(1, " ", 1);
    if (max == -1)
        while (s[++i])
            write(1, &s[i], 1);
    if (max > 0) {
        while (++i < (my_strlen(s) - max))
            my_putchar(' ');
        while (++j < max && s[j])
            write(1, &s[j], 1);
        i += j;
    }
    return (my_strlen(s));
}

int count_base_len(long nbr, char *base)
{
    int i = 0;

    if (nbr <= 0) {
        i++;
        nbr = -nbr;
    }
    while (nbr > 0) {
        i++;
        nbr /= my_strlen(base);
    }
    return (i);
}

int my_putnbr(long long nb)
{
    unsigned long long nbr;

    nbr = nb;
    if (nb < 0)
        nbr = -nb;
    if (nbr >= 10)
        my_putnbr(nbr / 10);
    my_putchar(nbr % 10 + 48);
    return (count_base_len(nb, "0123456789"));
}
