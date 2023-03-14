/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef _MY_H_
    #define _MY_H_
    #include <stdarg.h>
    #include <stdlib.h>
    #include <unistd.h>
    typedef struct s_flags {
        int precision;
        int point;
        int ind;
        int blank;
        int hashtag;
        int minus;
        int fill_z;
        int plus;
        char flag;
    } t_flags;
    int my_putchar(char c);
    int my_strlen(char *str);
    int my_putstr(char *s, int max);
    int my_putnbr(long long nb);
    char *my_convert_base(long nb, char *base);
    int count_base_len(long nbr, char *base);
    int in_charset(char c, char *charset);
    int my_getnbr(char *str);
    int decrease_p_flag(t_flags flags, long nb, char *base);
    int my_printf_hub(va_list ap, t_flags flags);
    int print_s_s(char *str, t_flags flags);
    int print_c(char c, t_flags flags);
    int print_d_i(int nb, t_flags flags);
    int print_u_b(long nb, t_flags flags);
    char *my_evil_str(char *str);
    t_flags init_struct(void);
    int print_x_x_p(long nb, t_flags flags);
    int print_o(long nb, t_flags flags);
    int count_octal_len(char *str);
    int my_octal_showstr(char *str, int index);
    t_flags fix_precision(t_flags flags, long nb);
    int my_printf(const char *format, ...);
    int print_minus_integer(int nb);
#endif
