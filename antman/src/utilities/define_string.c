/*
** EPITECH PROJECT, 2022
** define_string
** File description:
** antman
*/

#include "antman.h"

char *define_string(char *path, int fd)
{
    struct stat stat_t;
    char *string = NULL;

    stat(path, &stat_t);
    string = malloc(stat_t.st_size + 1);
    if (!string)
        return NULL;
    string[stat_t.st_size + 1] = '\0';
    if(!(read(fd, string, stat_t.st_size)))
        return NULL;
    return string;
}
