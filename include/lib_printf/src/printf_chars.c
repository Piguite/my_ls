/*
** EPITECH PROJECT, 2022
** siuu
** File description:
** my_printf_chars
*/



#include "../include/my.h"

int count_octal_len(char *str)
{
    int count = 0;
    int tmp;
    int i = -1;

    if (str == NULL)
        return (0);
    while (str[++i]) {
        tmp = str[i];
        if (str[i] < 0)
            tmp += 256;
        if (tmp < 32 || tmp > 126)
            count += 4;
    }
    return (count);
}

int my_octal_showstr(char *str, int index)
{
    int i = -1;
    char *hex = "01234567";
    int tmp;

    while (str[++i]) {
        tmp = str[i];
        if (str[i] < 0)
            tmp += 256;
        if (tmp < 32 || tmp > 126) {
            index += my_putchar('\\');
            index += my_putchar('0');
            index += my_putchar(hex[tmp / 8]);
            index += my_putchar(hex[tmp % 8]);
        } else
            index += my_putchar(str[i]);
    }
    return (index);
}

int print_s_s(char *s, t_flags flags)
{
    flags.precision -= (my_strlen(s) + count_octal_len(s));
    while (flags.precision-- > 0 && !flags.minus)
        flags.ind += my_putchar(' ');
    if (flags.flag == 's') {
        if (!s)
            flags.ind += my_putstr("(null)", flags.point);
        else
            flags.ind += my_putstr(s, flags.point);
    } else
        flags.ind += my_octal_showstr(s, flags.ind);
    if (flags.minus)
        flags.precision++;
    while (flags.precision-- > 0 && flags.minus)
        flags.ind += my_putchar(' ');
    return (flags.ind);
}

int print_c(char c, t_flags flags)
{
    flags.precision--;
    while (flags.precision-- > 0 && !flags.minus)
        flags.ind += my_putchar(' ');
    if (flags.flag == 'c')
        flags.ind += my_putchar(c);
    if (flags.minus)
        flags.precision++;
    while (flags.precision-- > 0 && flags.minus)
        flags.ind += my_putchar(' ');
    return (flags.ind);
}
