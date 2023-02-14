/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** antman
*/

#include "giantman.h"

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

int getnbr_at(char *string, global_t *global)
{
    int count = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == global->data_decompress)
            count++;
    }
    return count;
}

int call_functions(global_t *global, char *string)
{
    if (!global || !string)
        return 84;
    if (!(global->list = init_list(global, string)))
        return 84;
    if (!(global->list = fill_list(global, string)))
        return 84;
    if (!global || !global->list)
        return 84;
}

int free_all(int fd, global_t *global, char *string)
{
    if (call_functions(global, string) == 84)
        return 84;
    if (print_decompressed(global, string) == 84)
        return 84;
    close(fd);
    destroy_list(global->list);
    free(global);
    return 0;
}

int giantman(char *path, int type, char **argv)
{
    int fd = open(path, O_RDONLY);
    char *string = NULL;
    global_t *global = malloc(sizeof(global_t));

    if (!(string = define_string(path, fd)))
        return 84;
    if (fd == -1 || !global || !string)
        return 84;
    if (define_data(global, argv) == 84)
        return 84;
    global->nbr_at = getnbr_at(string, global);
    if (global->nbr_at == 0) {
        my_putstr(string);
        return 0;
    }
    return free_all(fd, global, string);
}
