/*
** EPITECH PROJECT, 2022
** antman
** File description:
** antman
*/

#include "antman.h"

int define_data(global_t *global, char **argv)
{
    if (!argv || !global)
        return 84;
    if (argv[2][0] == '1') {
        global->cur_data = ' ';
        global->data_decompress = '~';
    }
    if (argv[2][0] == '2') {
        global->cur_data = '"';
        global->data_decompress = '~';
    }
    if (argv[2][0] == '3') {
        global->cur_data = '\n';
        global->data_decompress = '~';
    }
}

int displayall(global_t *global, char *string)
{
    if (!global || !string)
        return 84;
    if (my_strlen(string) < my_strlen(global->words) + my_strlen(global->pos))
        my_putstr(string);
    else {
        my_putstr(global->words);
        my_putstr(global->pos);
    }
}

int call_functions(global_t *global, char *string)
{
    if (!global || !string)
        return 84;
    global->list = init_list(string, global);
    global->list = fill_list(string, global);
    if (displayall(global, string) == 84 || !global->list)
        return 84;
}

int end_prog(global_t *global)
{
    if (destroy_list(global->list) == 84)
        return 84;
    free(global);
    return 0;
}

int antman(char *path, int type, char **argv)
{
    int fd = open(path, O_RDONLY);
    char *string = define_string(path, fd);
    global_t *global = malloc(sizeof(global_t));

    if (!global || !string)
        return 84;
    global->list = malloc(sizeof(elem_t));
    global->i = 2;
    if (define_data(global, argv) == 84)
        return 84;
    if (fd == -1 || !global || !global->list || !string || !global->i)
        return 84;
    if (check_string(string, global) == 84)
        return 84;
    if (call_functions(global, string) == 84)
        return 84;
    close(fd);
    return end_prog(global);
}
