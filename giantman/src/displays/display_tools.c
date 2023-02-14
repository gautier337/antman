/*
** EPITECH PROJECT, 2022
** antman
** File description:
** decompress a file
*/

#include "giantman.h"

void my_putchar(char c)
{
    write (1, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
