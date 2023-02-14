/*
** EPITECH PROJECT, 2022
** antman
** File description:
** decompress a file
*/

#ifndef GIANTMAN_H_
    #define GIANTMAN__H_

    #include "struct.h"
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdlib.h>

    void my_putstr(char const *str);
    int check_errors(int argc, char **argv);
    int check_file(char *argv);
    char *get_file(char *file);
    int giantman(char *path, int type, char **argv);
    int my_strlen(char const *str);
    int is_neg(char const *str);
    void my_putchar(char c);
    int my_getnbr(char const *str);
    char *my_strcat(char *dest, char const *src);
    int my_strcmp (char const *s1, char const *s2);
    int lenght_int(int nbr);
    char *convert_int(int nb);
    char *define_string(char *path, int fd);
    elem_t *create_list(int val, char *word);
    elem_t *add_node(elem_t *list, int val, char *word);
    void destroy_list(elem_t *list);
    void get_and_print_last(global_t *global, int nb);
    void get_and_print_word(global_t *global, int nb);
    int check_and_print_word(global_t *global, char *string);
    int print_decompressed(global_t *global, char *string);
    elem_t  *init_list(global_t *global, char *string);
    void add_word(global_t *global, char *word);
    elem_t *fill_list(global_t *global, char *string);
    void destroy_list(elem_t *list);

#endif /* !GIANTMAN_H_ */
