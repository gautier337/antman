/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress a file
*/

#ifndef ANTMAN_H_
    #define ANTMAN_H_

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
    int my_getnbr(char const *str);
    int is_neg(char const *str);
    int my_strlen(char const *str);
    char *my_putcstr(char *numbers);
    int antman(char *path, int type, char **argv);
    elem_t *create_list(int val, char *word);
    elem_t *add_node(elem_t *list, int val, char *word);
    int check_list_for_word(elem_t *list, char *word);
    char *my_strcat(char *dest, char const *src);
    char *convert_int(int nb);
    int my_strcmp (char const *s1, char const *s2);
    int check_string(char *string, global_t *global);
    elem_t *init_list(char *string, global_t *global);
    void add_word(global_t *global, char *word);
    elem_t *fill_list(char *string, global_t *global);
    void free_all(global_t *global, char *f_word);
    char *define_string(char *path, int fd);
    int destroy_list(elem_t *list);

#endif /* !ANTMAN_H_ */
