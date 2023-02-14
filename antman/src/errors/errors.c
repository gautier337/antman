/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress and decompress a file
*/

#include "antman.h"

int check_file(char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat file;

    stat(path, &file);
    if (S_ISDIR(file.st_mode)) {
        my_putstr("Invalid File (folder)\n");
        return 84;
    }
    if (fd == -1) {
        my_putstr("Invalid File\n");
        close(fd);
        return 84;
    }
    close(fd);
    return 0;
}

int check_errors(int argc, char **argv)
{
    if (!argv)
        return 84;
    if (argc != 3) {
        my_putstr("Invalid args, check with -h flag\n");
        return 84;
    }
    if (argv[2][0] >= '4' || argv[2][0] <= '0') {
        return 84;
    }
    if (check_file(argv[1]) == 84)
        return 84;
    return 0;
}

int check_string(char *string, global_t *global)
{
    int nbr_space = 0;

    if (!string || !global)
        return 84;
    for (int i = 0; string[i] != '\0' && nbr_space == 0; i++)
        if (string[i] == global->cur_data)
            nbr_space++;
    if (nbr_space != 1)
        my_putstr(string);
}
