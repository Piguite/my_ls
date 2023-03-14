/*
** EPITECH PROJECT, 2022
** siuu
** File description:
** my_printf_hub
*/


#include "../include/my.h"

int my_printf_hub(va_list ap, t_flags flags)
{
    long tmp;

    if (in_charset(flags.flag, "Ss"))
        return (print_s_s(va_arg(ap, char *), flags));
    if (in_charset(flags.flag, "c"))
        return (print_c(va_arg(ap, int), flags));
    if (in_charset(flags.flag, "di"))
        return (print_d_i(va_arg(ap, int), flags));
    if (in_charset(flags.flag, "ub")) {
        tmp = va_arg(ap, int);
        tmp = (tmp < 0 ? (4294967296 + tmp) : tmp);
        return (print_u_b(tmp, flags));
    }
    if (in_charset(flags.flag, "xXp"))
        return (print_x_x_p(va_arg(ap, long), flags));
    if (in_charset(flags.flag, "o"))
        return (print_o(va_arg(ap, int), flags));
    return (0);
}
