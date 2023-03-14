/*
** EPITECH PROJECT, 2022
** siuu
** File description:
** my_printf_main
*/



#include "../include/my.h"

t_flags init_struct(void)
{
    t_flags init;

    init.blank = 0;
    init.fill_z = 0;
    init.hashtag = 0;
    init.minus = 0;
    init.precision = 0;
    init.ind = 0;
    init.plus = 0;
    init.point = -1;
    return (init);
}

t_flags fix_flags(char c, t_flags flags)
{
    if (c == ' ')
        flags.blank++;
    if (c == '#')
        flags.hashtag++;
    if (c == '-')
        flags.minus++;
    if (c == '+')
        flags.plus++;
    if (c == '0')
        flags.fill_z++;
    return (flags);
}

int get_flag(va_list ap, char *str, int *i)
{
    t_flags flags = init_struct();
    int j = *i - 1;

    while (!in_charset(str[++j], "SbdioxXucsp") && str[j]) {
        if (!in_charset(str[j], " #+-0.123456789l%%")) {
            return (my_putchar('%'));
        }
        flags = fix_flags(str[j], flags);
        if (str[j] == '.')
            flags.point += my_getnbr(&str[j + 1]) + 1;
        if (str[j] >= '1' && str[j] <= '9' && str[j - 1] != '.') {
            flags.precision += my_getnbr(&str[j]);
            j += count_base_len(my_getnbr(&str[j]), "0123456789") - 1;
        }
    }
    *i = j;
    flags.flag = str[j];
    return (my_printf_hub(ap, flags));
}

int my_printf(const char *format, ...)
{
    int i = -1;
    int index = 0;
    va_list ap;
    va_start(ap, format);

    while (format[++i] && i < my_strlen((char *)format)) {
        if (format[i] == '%' && format[i + 1] == '%') {
            my_putchar('%');
            index++;
            i += 2;
        }
        if (format[i] == '%' && format[i + 1] != '%' && format[i + 1]) {
            index += get_flag(ap, (char *)format, &i);
        } else
            index += my_putchar(format[i]);
    }
    va_end(ap);
    return (index);
}
