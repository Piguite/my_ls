/*
** EPITECH PROJECT, 2022
** siuu
** File description:
** my_printf_parsing
*/



#include "../include/my.h"

int in_charset(char c, char *charset)
{
    int i = -1;

    while (charset[++i])
        if (c == charset[i])
            return (1);
    return (0);
}

int my_getnbr(char *str)
{
    long int res = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        res = res * 10 + str[i] - '0';
        i++;
        if (res > 2147483648 || (res == 2147483648 && sign == 1))
            return (0);
    }
    return (res * sign);
}

int decrease_p_flag(t_flags flags, long nb, char *base)
{
    int i = my_strlen(my_convert_base(nb, base));

    if (flags.flag == 'p' && nb == 0)
        i = 5;
    return (i);
}

t_flags fix_precision(t_flags flags, long nb)
{
    char flag = flags.flag;

    if (flags.fill_z)
        flags.precision++;
    if ((flags.blank && !flags.plus) || (flags.plus && !flags.fill_z))
        if (flag == 'p' && nb != 0)
            flags.precision--;
    return (flags);
}

int print_minus_integer(int nb)
{
    if (nb < 0)
        my_putchar('-');
    return (0);
}
