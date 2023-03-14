/*
** EPITECH PROJECT, 2022
** siuu
** File description:
** my_printf_integers
*/



#include "../include/my.h"

t_flags my_print_blank(t_flags flags, long nb)
{
    if (flags.blank && !flags.plus && flags.flag == 'p') {
        flags.ind += my_putchar(' ');
        flags.precision--;
    }
    if ((flags.hashtag && nb != 0) || (flags.flag == 'p' && nb != 0)) {
        if (flags.plus && flags.flag == 'p') {
            flags.ind += my_putchar('+');
            flags.precision--;
        }
        flags.ind += my_putchar('0');
        if (flags.flag != 'o') {
            flags.flag == 'p' ? my_putchar('x') : my_putchar(flags.flag);
            flags.ind++;
            flags.precision -= 2;
        } else
            flags.precision--;
    }
    while (flags.precision-- > 0 && flags.fill_z && !flags.minus)
        flags.ind += my_putchar('0');
    return (flags);
}

int print_d_i(int nb, t_flags flags)
{
    flags.precision -= count_base_len((long)nb, "0123456789");
    if (flags.fill_z)
        flags.precision++;
    if (flags.blank && !flags.plus && nb >= 0)
        flags.ind += my_putchar(' ');
    if ((flags.plus && nb >= 0) || (flags.blank && !flags.plus && nb >= 0))
        flags.precision--;
    while (flags.precision-- > 0 && !flags.minus && !flags.fill_z)
        flags.ind += my_putchar(' ');
    if (flags.plus && nb >= 0)
        flags.ind += my_putchar('+');
    flags.ind += print_minus_integer(nb);
    while (flags.precision-- > 0 && flags.fill_z && !flags.minus)
        flags.ind += my_putchar('0');
    flags.ind += my_putnbr(nb);
    if (flags.minus)
        flags.precision += flags.fill_z ? 1 : 2;
    while (flags.precision-- > 0 && flags.minus)
        flags.ind += my_putchar(' ');
    return (flags.ind);
}

int print_u_b(long nb, t_flags flags)
{
    flags.precision -= count_base_len((long)nb, "0123456789");
    if (flags.fill_z)
        flags.precision++;
    while (flags.precision-- > 0 && !flags.minus && !flags.fill_z)
        flags.ind += my_putchar(' ');
    while (flags.precision-- > 0 && flags.fill_z && !flags.minus)
        flags.ind += my_putchar('0');
    if (flags.flag == 'b')
        flags.ind += my_putstr(my_convert_base(nb, "01"), flags.point);
    else
        flags.ind += my_putnbr(nb);
    if (flags.minus)
        flags.precision += flags.fill_z ? 1 : 2;
    while (flags.precision-- > 0 && flags.minus)
        flags.ind += my_putchar(' ');
    return (flags.ind);
}

int print_x_x_p(long nb, t_flags flags)
{
    char flag = flags.flag;
    char *base = (flag == 'X' ? "0123456789ABCDEF" : "0123456789abcdef");

    flags.precision -= decrease_p_flag(flags, nb, base);
    flags = fix_precision(flags, nb);
    while (flags.precision-- > 0 && !flags.minus && !flags.fill_z) {
        flags.ind += my_putchar(' ');
        if ((flags.hashtag || flag == 'p') && flags.precision == 2 && nb != 0)
            break;
    }
    flags = my_print_blank(flags, nb);
    if (flag == 'p' && nb == 0)
        flags.ind += my_putstr("(nil)", flags.point);
    else
        flags.ind += my_putstr(my_convert_base(nb, base), flags.point);
    if (flags.minus)
        flags.precision += flags.fill_z ? 1 : 2;
    while (flags.precision-- > 0 && flags.minus)
        flags.ind += my_putchar(' ');
    return (flags.ind);
}

int print_o(long nb, t_flags flags)
{
    char *res = my_convert_base(nb, "01234567");

    flags.precision -= my_strlen(res);
    if (flags.fill_z)
        flags.precision++;
    while (flags.precision-- > 0 && !flags.minus && !flags.fill_z) {
        flags.ind += my_putchar(' ');
        if (flags.hashtag && flags.precision == 1 && nb != 0)
            break;
    }
    flags = my_print_blank(flags, nb);
    flags.ind += my_putstr(res, flags.point);
    if (flags.minus)
        flags.precision += flags.fill_z ? 1 : 2;
    while (flags.precision-- > 0 && flags.minus)
        flags.ind += my_putchar(' ');
    free(res);
    return (flags.ind);
}
