/*
** EPITECH PROJECT, 2022
** siuu
** File description:
** my_printf_convertor
*/



#include "../include/my.h"

char *my_evil_str(char *str)
{
    int i = -1;
    int len = my_strlen(str);
    char a;

    while (++i < --len) {
        a = str[i];
        str[i] = str[len];
        str[len] = a;
    }
    return (str);
}

char *my_itoa_recurs(long nb, int count, char *res, char *base)
{
    unsigned long val;
    unsigned int len = my_strlen(base);

    val = nb;
    if ((val < len && len != 10) || (len == 10 && val > -10 && val < 10)) {
        if (!(res = malloc(sizeof(char) * (count + 2))))
            return (NULL);
        res[count + 1] = '\0';
    } else
        res = my_itoa_recurs(val / len, count + 1, res, base);
    res[count] = base[val % len];
    return (res);
}

char *my_convert_base(long nb, char *base)
{
    char *res = NULL;

    if (nb < 0)
        nb += 4294967296;
    res = my_itoa_recurs(nb, 0, res, base);
    if (res == NULL)
        return (NULL);
    return (my_evil_str(res));
}
