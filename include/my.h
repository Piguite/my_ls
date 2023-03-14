/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef _MY_H_
    #define _MY_H_
    #include <dirent.h>
    #include <grp.h>
    #include <pwd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <time.h>
    #include <unistd.h>
    typedef struct s_file {
        char *name;
        char *path;
        unsigned char type;
        int already_op;
        int blocks;
    } file;
    typedef struct s_arg {
        file *file;
        struct s_arg *next;
        struct stat stat;
    } t_arg;
    typedef struct s_folder {
        char *path;
        struct stat stat;
        struct s_folder *next;
    } t_folder;
    typedef struct s_int {
        int blocks;
        int ct;
    } t_i;
    typedef struct s_render {
        int f_l;
        int f_r;
        int f_d;
        int f_big_r;
        int f_t;
        int return_value;
        t_folder *name;
        t_i nb;
    } t_render;
    int my_strlen(char *s);
    int my_strcmp(char *s1, char *s2);
    int in_charset(char c, char *charset);
    char *my_strcat(char *dest, char const *src);
    char *my_strdup(char *src);
    char *my_advanced_strcat(char *s1, char *s2);
    void my_lstclear_arg(t_arg **lst);
    void my_lstclear_folder(t_folder **lst);
    void my_concat_list(t_arg **begin1, t_arg *begin2);
    t_folder *my_create_elem_folder(char *data, struct stat t_stat);
    void my_list_push_back_folder(t_folder **b_l, char *d, struct stat t);
    void my_lstclear_folder(t_folder **lst);
    void enumerating_lst(t_arg *lst, t_arg **lst_main, t_render *render);
    t_arg *get_folder_info(char *path, t_arg **lst_main, t_render *render);
    t_arg *my_create_elem_arg(struct dirent *data, struct stat stat, char *p);
    void my_list_push_arg(t_arg **l, struct dirent *d, struct stat s, char *p);
    void my_lstclear_arg(t_arg **lst);
    int my_list_size(t_arg *begin);
    t_render *init_render(void);
    int my_list_size_bis(t_folder *begin);
    void my_sort_list_alpha_arg(t_arg **begin, int time);
    void my_sort_list_alpha_folder(t_folder **begin, int time);
    void my_rev_list_arg(t_arg **begin);
    void sort_arg_flags(t_render *render, t_arg **lst);
    void my_rev_list_folder(t_folder **begin);
    void sort_folder_flags(t_render *render, t_folder **lst);
    t_render *get_flags(char **av, struct stat t_stat, int i, int error);
    t_arg *my_ls(t_render *tmp);
    int my_ls_main(char **av);
    void printer_right(t_arg *lst);
    void printer_right_folder(t_folder *lst);
    void print_arg(t_render *render, t_arg *lst, int size);
    void print_flag_l_folder(t_render *render, t_folder *lst);
    int print_perror(void *error, char *by_the_way, t_render *render);
    int maj_byte(unsigned int nb);
    int min_byte(unsigned int nb);
    void print_type(struct stat t_stat);
    void put_error(char c);
    int my_printf(const char *format, ...);
#endif
